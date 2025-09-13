#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int>> arr;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,x,m;
    cin >> n >> x;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr[i] = {m, i + 1};
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if ((arr[i].first + arr[j].first) == x)
        {
            break;
        }
        if ((arr[i].first + arr[j].first) > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (i < j)
    {
        cout << arr[i].second << " " << arr[j].second << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}