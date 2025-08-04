#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;

    int o = 1, e = 2;

    if(n == 2 || n == 3) cout<<"NO SOLUTION\n";
    else {
    vector<int> odd, even;
    while(o<=n){
        odd.push_back(o);
        o+=2;
    }

    while(e<=n){
        even.push_back(e);
        e+=2;
    }

    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());

    for(int i=0;i<even.size();i++) odd.push_back(even[i]);

    for(int i=0;i<odd.size();i++){
        cout<<odd[i]<<" ";
    }

    cout<<endl;
}

    
}