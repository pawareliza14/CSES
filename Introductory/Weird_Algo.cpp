#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n ;
    cin>>n;

    while(n!=1){
        cout<<n<<" ";
        if(n%2) n = (n*3) + 1;
        else n /= 2;
    }

    cout<<1<<endl;
}