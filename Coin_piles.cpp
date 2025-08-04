// Read article it was also formula type question
#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
 int t;
 cin>>t;
 while (t--)
 {
    /* code */
   int a,b;
    cin>>a>>b;

    if(b > a) swap(a,b);

    if(((a+b)%3) || 2*b < a) cout<<"NO\n";
    else cout<<"YES\n"; 
}
    
    
}
