#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int i, int s1,int s2, int &ans, vector<int>&nums){
    if(i==-1){
        ans = min(ans, abs(s1-s2));
        return;
    }
    solve(i-1, s1+nums[i],s2,ans,nums);
    solve(i-1,s1,s2+nums[i],ans, nums);

    return;

}
signed main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int ans = INT_MAX;
    solve(n-1, 0,0,ans, nums);

    cout<<ans<<endl;

    return 0;


}