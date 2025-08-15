// Not working code
#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    deque<int> dq;
    unordered_map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        while(!dq.empty() && mpp[nums[dq.back()]] < mpp[nums[i]]) 
        {
            dq.pop_back(); 
        }
    
        dq.push_back(i);
        while(dq.front() <= (i-k)) {
            mpp[nums[dq.front()]]--;
            if (mpp[nums[dq.front()]] == 0)
                mpp.erase(nums[dq.front()]);
            dq.pop_front();
        }
        if(i >= (k-1)) cout<<nums[dq.front()]<<" ";
    }

    cout<<endl;
}