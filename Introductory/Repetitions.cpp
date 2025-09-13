#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    string s;
    cin>>s;

    int n = s.size();

    int maxi =1, cnt = 1;

    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]) cnt++;
        else cnt = 1;

        maxi = max(cnt, maxi);
    }

    cout<<maxi<<endl;
}
