#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;

void input_generator(vector<int> &arr, int a, int b, int c)
{
    for (int i = 1; i < n; i++)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
}

signed main(){
    int k;
    cin>>n>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<int> nums(n);
    nums[0] = x;

    input_generator(nums, a, b, c);

    int fin = 0;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && nums[i] < nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        while (dq.front() <= (i - k))
            dq.pop_front();
        if (i >= (k - 1))
           fin ^= nums[dq.front()];
    }

    cout<<fin<<endl;
}
