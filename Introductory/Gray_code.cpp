#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int N;
void graycode(int num)
{
    int ans = num ^ (num >> 1);
    for (int i = N - 1; i >= 0; i--)
    {
        cout << ((ans >> i) & 1);
    }
    cout << "\n";
}

signed main(){
    cin>>N;

    int num  = (1 << N) - 1;

    for(int i=0;i<=num;i++){
        graycode(i);
    }

    cout<<endl;
}