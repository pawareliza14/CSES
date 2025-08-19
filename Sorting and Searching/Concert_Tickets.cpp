#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
multiset<int> ml;

// Approach 1: Not optimised
// int floor(vector<int>&a, int target){
//     int l = 0, r = a.size()-1;
//     int ans = -1,indx = -1;

//     while(l <= r){
//         int mid = (l+r)/2;

//         if(a[mid]<=target){
//             indx = mid;
//             ans = a[mid];
//             l= mid+1;
//         } else r = mid-1;
//     }

//     if(ans != -1) {
//         auto it= next(ml.begin(), indx);
//         ml.erase(it);
//     }
//     return ans;

// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int n,m;
//     cin>>n>>m;

//     vector<int>  b(m); 

//     for(int i=0;i<n;i++) {
//         int tmp;
//         cin>>tmp;
//         ml.insert(tmp);
//     }

//     for(int i=0;i<m;i++) cin>>b[i];

//     for(int i=0;i<m;i++){
//         if(ml.empty()) {
//             cout<<-1<<endl;
//             continue;
//         }
//         vector<int> a (ml.begin(), ml.end());
//         cout<<floor(a,b[i])<<endl;
//     }


// }


//Approach 2: GFG (problem was lack of knowledge about the data structure use)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        ml.insert(tmp);
    }

    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];

        // if(ml.empty()){
        //     cout<<-1<<endl;
        //     continue;
        // }

        auto it = ml.upper_bound(b[i]);
        if(it==ml.begin()){
            cout<<-1<<endl;
        } else {
            it--;
            cout<<*it<<endl;
            ml.erase(it);
        }
    }

}