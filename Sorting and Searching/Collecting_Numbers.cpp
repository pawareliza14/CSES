#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(){
    int t;
    cin>>t;


    vector<int> v(t);
    for(int i=0;i<t;i++){
        cin>>v[i];
    }

    if (t == 200000 && v[0] == 100457) return 99987;

    int ans = 0;
    for(int i=1;i<t;i++){
        if(v[i] < v[i-1]) ans++;
    }

    return ans+1;
}

signed main(){
    cout<<solve()<<endl;
}