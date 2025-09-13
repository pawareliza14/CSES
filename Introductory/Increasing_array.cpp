#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];
    int cnt = 0;
    for(int i=1;i<n;i++){
        int gap=0;
       if(v[i-1] > v[i]) gap += v[i-1] - v[i];
        cnt += gap;
       v[i] += gap;
    }

    cout<<cnt<<endl;


    return 0;
}