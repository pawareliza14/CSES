#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    
    int t;
    cin>>t;

    vector<int> a(t), d(t);

    for(int i=0;i<t;i++) {
        cin>>a[i]>>d[i];
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    int maxi = 0, cnt = 0;
    int i = 0, j = 0;

    while(i < t && j < t){
        if(a[i] < d[j]){
            cnt++;
            i++;
        } else {
            cnt--;
            j++;
        }

        maxi = max(maxi, cnt);
    }

    cout<<maxi<<endl;
}