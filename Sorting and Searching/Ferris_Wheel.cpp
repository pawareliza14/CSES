#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    
    int l=0, r=n-1,cnt=0;

    while(l <= r){
        if((arr[r]+arr[r-1]) <= k) {
            r-=2;
        }
        else if((arr[l]+arr[r]) <= k){
            r--;
            l++;
        } else {
            r--;
        } 
        cnt++;
    }

    cout<<cnt<<endl;
}