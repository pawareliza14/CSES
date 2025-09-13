#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    string s;
    cin>>s;

    int n = s.size();

    map<char, int> mpp;

    for(auto e : s) mpp[e]++;

    int od = 0;
    char odc;

    for(auto e: mpp) {
        if(e.second % 2){ od++;
        mpp[e.first]--;
        odc = e.first;
    }
    }

    if(od >= 2) cout<<"NO SOLUTION\n";

    else {
        string t;
        for(auto it: mpp){
            int r = it.second;
            // cout<<it.first<<" "<<it.second<<endl;

            while(r > it.second/2){
                t += it.first;
                r--;
            }
        }

        string ans = "";
        ans +=  t;
        if(od)ans += odc;
        reverse(t.begin(), t.end());
        ans += t;
        cout<<ans<<endl;
    }



}