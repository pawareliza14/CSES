#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    int sum =0 , maxi =LLONG_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
        maxi = max(sum, maxi);

        if(sum < 0) sum = 0;

    }

    cout<<maxi<<endl;
}