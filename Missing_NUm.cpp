#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;

    int to = (n*(n+1)) / 2;

    for(int i=0;i<n-1;i++) {
        int tmp;
        cin>>tmp;
        to -= tmp;
    }

    cout<<to<<endl;
}