//Another Greedy quesiton 
// No intution arose GFG
#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve (){
    int t,sum = 0;
    cin>>t;

    vector<int> v(t);

    for(int i=0;i<t;i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int cuMax = 1;
    for(int i=0;i<t;i++){
        if((cuMax) < v[i]) return cuMax;
        cuMax += v[i];
    }

    return cuMax;

}

signed main(){
    cout<<solve()<<endl;
}