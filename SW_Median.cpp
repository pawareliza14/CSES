//Code does not work
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    multiset<int> window;
    auto mid = window.begin();

    for (int i = 0; i < n; ++i)
    {
        // Insert new element
        window.insert(nums[i]);
        if (i == 0)
            mid = window.begin();
        else if (nums[i] < *mid)
            mid--;

        // Remove element that's sliding out
        if (i >= k)
        {
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }

        // Output median
        if (i >= k - 1)
        {
            if (k % 2 == 0)
            {
                auto mid2 = mid;
                ++mid2;
                cout << min(*mid, *mid2) << " "; // lower median
            }
            else
            {
                cout << *mid << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
