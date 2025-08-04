#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;

    for(int k=1;k<=n;k++) cout<<((k*k)*(k*k-1)/2) - (4*(k-1)*(k-2))<<endl;
}
