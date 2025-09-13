#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve(int i, vector<int> &v, int target, vector<int> &emp)
{
    if (target == 0)
    {
        return true;
    }

    if (i < 0 || target < 0)
        return false;

    emp.push_back(v[i]);
    if (solve(i - 1, v, target - v[i], emp))
    {
        return true;
    }

    emp.pop_back();
    return solve(i - 1, v, target, emp);
}

signed main()
{
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    vector<int> v;
    if (total % 2)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    vector<int> emp;
    if (solve(n - 1, v, total / 2, emp))
    {
        cout << "YES\n";
        sort(emp.begin(), emp.end());
        int j = 0;
        cout<<emp.size()<<endl;

        for(int i=0;i<emp.size();i++) cout<<emp[i]<<" ";
        cout<<endl;
        cout<<n-emp.size()<<endl;

        for(int i=1;i<=n;i++){
            if(emp[j] != i ) cout<<i<<" ";
            else j++;
        }
        
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
