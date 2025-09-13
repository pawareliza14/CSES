//Generate permutaions backtracking approach imp

#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate unique permutations
void generatePermutations(int index, string &s, vector<string> &result)
{
    if (index == s.size())
    {
        result.push_back(s); // Found a valid permutation
        return;
    }

    unordered_set<char> used; // To avoid duplicate swaps at this level
    for (int i = index; i < s.size(); i++)
    {
        if (used.count(s[i]))
            continue; // Skip duplicates

        used.insert(s[i]);
        swap(s[index], s[i]);                       // Choose
        generatePermutations(index + 1, s, result); // Explore
        swap(s[index], s[i]);                       // Unchoose (backtrack)
    }
}

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end()); // Sort to ensure lexicographic order
    vector<string> result;

    generatePermutations(0, s, result);

    sort(result.begin(), result.end()); // Optional: ensures output is ordered

    cout << result.size() << "\n";
    for (const string &perm : result)
    {
        cout << perm << "\n";
    }

    return 0;
}
