#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int M = pow(10,9) + 7;
    int n;
    cin>>n;

    int ans = 1;
    int base = 2;
    while(n){
        if(n&1LL) ans = (ans*base) % M;
        base = (base*base) % M;
        n >>= 1;
    }
   cout<<ans<<endl;
}
