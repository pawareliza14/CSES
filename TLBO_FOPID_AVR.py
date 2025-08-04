import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import control as ctrl
import random

# ----------------------
# AVR + FOPID System Setup
# ----------------------

def oustaloup_approx(order, N=5, wL=0.01, wH=100):
    s = ctrl.tf([1, 0], [1])
    num = 1
    den = 1
    for k in range(-N, N + 1):
        wk = wL * (wH / wL) ** ((k + N + 0.5) / (2 * N + 1))
        num *= (s + wk ** 0.5)
        den *= (1 + wk ** 0.5 * s ** -1)
    return num / den

def fopid_tf(Kp, Ki, Kd, lam, mu):
    s = ctrl.tf([1, 0], [1])
    # Oustaloup approximation (simplified)
    Dlam = oustaloup_approx(lam)
    Dmu = oustaloup_approx(mu)
    return Kp + Ki / Dlam + Kd * Dmu

def avr_model():
    s = ctrl.tf([1, 0], [1])
    G_avr = (10) / ((0.1*s + 1)*(0.01*s + 1)*(0.05*s + 1)*(0.07*s + 1))
    return G_avr

def evaluate_fitness(params):
    Kp, Ki, Kd, lam, mu = params
    if not (0 <= lam <= 1 and 0 <= mu <= 1):
        return 1e6  # Large penalty for invalid fractional orders
    try:
        C = fopid_tf(Kp, Ki, Kd, lam, mu)
        G = ctrl.feedback(C * avr_model(), 1)
        t, y = ctrl.step_response(G, T=np.linspace(0, 2, 1000))
        error = 1 - y
        itae = np.trapz(t * np.abs(error), t)
        if np.any(np.isnan(itae)) or np.isinf(itae):
            return 1e6
        return itae
    except Exception:
        return 1e6

# ----------------------
# TLBO Setup
# ----------------------

Runs = 5
Iterations = 10
dim = 5  # Kp, Ki, Kd, lambda, mu
pop_size = 10
lb = np.array([0, 0, 0, 0, 0])
ub = np.array([100, 50, 50, 1, 1])
all_iterations = []

best_val = np.zeros(Runs)

for run in range(Runs):
    Positions = np.random.uniform(lb, ub, (pop_size, dim))
    finval = np.zeros(Iterations)

    for k in range(Iterations):
        fitness_vals = np.array([evaluate_fitness(ind) for ind in Positions])
        best_idx = np.argmin(fitness_vals)
        best_pos = Positions[best_idx].copy()
        best_score = fitness_vals[best_idx]

        # Teacher Phase
        mean_pos = np.mean(Positions, axis=0)
        TF = random.choice([1, 2])
        for i in range(pop_size):
            new_pos = Positions[i] + np.random.rand(dim) * (best_pos - TF * mean_pos)
            new_pos = np.clip(new_pos, lb, ub)
            if evaluate_fitness(new_pos) < fitness_vals[i]:
                Positions[i] = new_pos

        # Learner Phase
        for i in range(pop_size):
            partner_idx = i
            while partner_idx == i:
                partner_idx = random.randint(0, pop_size - 1)

            learner = Positions[i]
            partner = Positions[partner_idx]
            new_pos = learner.copy()

            if evaluate_fitness(learner) < evaluate_fitness(partner):
                new_pos += np.random.rand(dim) * (learner - partner)
            else:
                new_pos += np.random.rand(dim) * (partner - learner)

            new_pos = np.clip(new_pos, lb, ub)
            if evaluate_fitness(new_pos) < evaluate_fitness(learner):
                Positions[i] = new_pos

        # Store best of iteration
        fitness_vals = np.array([evaluate_fitness(ind) for ind in Positions])
        best_idx = np.argmin(fitness_vals)
        best_pos = Positions[best_idx].copy()
        best_score = fitness_vals[best_idx]
        finval[k] = best_score

        all_iterations.append({
            "Run": run + 1,
            "Iteration": k + 1 + run * Iterations,
            "Kp": best_pos[0],
            "Ki": best_pos[1],
            "Kd": best_pos[2],
            "lambda": best_pos[3],
            "mu": best_pos[4],
            "Fitness": best_score
        })

        if (k + 1) % 20 == 0 or (k + 1) == Iterations:
            print(f"Run {run+1}, Iteration {k+1}: Best ITAE = {best_score:.6f}")

    best_val[run] = np.min(finval)
    print(f"Final Best solution for Run {run+1}: {best_val[run]:.6f}")

# ----------------------
# Summary & Plot
# ----------------------

print("\nFinal Results across all runs:")
print("Best:", np.min(best_val))
print("Worst:", np.max(best_val))
print("Mean:", np.mean(best_val))
print("Std Dev:", np.std(best_val))

df = pd.DataFrame(all_iterations)
summary = pd.DataFrame({
    "Run": ["Best", "Worst", "Mean", "Std Dev"],
    "Fitness": [np.min(best_val), np.max(best_val), np.mean(best_val), np.std(best_val)]
})

file_path = "TLBO_FOPID_AVR.xlsx"
with pd.ExcelWriter(file_path, engine='openpyxl') as writer:
    df.to_excel(writer, index=False, sheet_name='Iteration Data')
    summary.to_excel(writer, index=False, sheet_name='Summary')

# Plotting
plt.figure(figsize=(12, 6))
for run in range(1, Runs + 1):
    run_data = df[df["Run"] == run]
    plt.plot(run_data["Iteration"], run_data["Fitness"], label=f"Run {run}")

plt.xlabel("Iteration")
plt.ylabel("ITAE Fitness Value")
plt.title("Convergence Curve - TLBO (FOPID Tuning for AVR)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
