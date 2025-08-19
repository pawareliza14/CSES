#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long
 
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    set<int> st;

    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        st.insert(tmp);
    }

    cout<<st.size()<<'\n';
    return 0;

}
