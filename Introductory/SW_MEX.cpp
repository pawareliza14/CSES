#include<iostream>
#include<bits/stdc++.h>
#define int long long
const int MAXN = 200005;

using namespace std;

set<int> miss;
unordered_map<int, int> mpp;

void init(){
    for(int i=0;i<MAXN;i++){
        miss.insert(i);
    }
}

int get(){
    return *miss.begin();
}

void add(int n){
    mpp[n]++;

    if(mpp[n] >= 1){
        miss.erase(n);
    }
}

void remove(int n){
    mpp[n]--;

    if(mpp[n] == 0){
        miss.insert(n);
    }
}


signed main(){
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0;i<n;i++) {cin>>nums[i];
}

    init();
    int l =  0;

    for(int i=0;i<n;i++){
        add(nums[i]);

        if(l <= (i-k)) {
            remove(nums[l]);
            l++;
}
      if(i >= (k-1)) cout<<get()<<" ";
    }

    cout<<endl;
}