#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n;
    cin>>n;

    if (n < 0)
        return -1;

    // Initialize result
    int count = 0;

    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    cout<<count<<endl;

    return 0;
}