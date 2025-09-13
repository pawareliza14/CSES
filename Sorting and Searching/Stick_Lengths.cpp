#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<int>&b, int look){
    int ans = 0;
    for(int i=0;i<b.size();i++){
        ans += abs(b[i] - look);
    }

    return ans;
}

signed main(){
    int t;
    cin>>t;

    vector<int> v(t);
    for(int i=0;i<t;i++) cin>>v[i];

    sort(v.begin(), v.end());

    int look = 0, ans = 0;

    if(t%2){ 
        look  = v[t/2];
        ans = solve(v,look);
    } else {
        ans = (solve(v,v[t/2]));
    }

    cout<<ans<<endl;

}