#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0;i<n;i++){ 
        cin>>nums[i];
    }

    unordered_map<int, int> mpp;
    int l = 0;

    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(l <= (i-k)) {
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }

        if(i >= (k-1)) cout<<mpp.size()<<" ";
    }

    cout<<endl;
}