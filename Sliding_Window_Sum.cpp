#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
void input_generator(vector<int>&arr, int a, int b, int c){
    for(int i=1;i<n;i++){
        arr[i] = (a*arr[i-1]+b) % c;
    }
}

signed main(){
    int k;
    cin>>n>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0] = x;

    input_generator(arr,a,b,c);
    
    int sum = 0;
    int finSum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    finSum = sum;
    int j = 0;

    for(int i=k;i<n;i++){
        sum -= arr[j];
        sum += arr[i];
        j++;


        finSum ^= sum;
    }

    cout<<finSum<<endl;

}