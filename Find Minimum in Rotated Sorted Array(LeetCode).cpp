#include <bits/stdc++.h>
using namespace std;
//  Find Minimum in Rotated Sorted Array(LeetCode)
int findMin(vector<int> &nums)
{
    int n = nums.size(), lo = 0, hi = n - 1, ans = 1e9;
    if (n == 1)
        return nums[0];
    else if (nums[lo] <= nums[hi])
        return nums[lo];
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        // 1st Region.
        if (nums[mid] >= nums[0])
        {
            lo = mid + 1;
        }
        // 2nd region
        else
        {
            ans = min(ans, nums[mid]);
            hi = mid - 1;
        }
    }
    return ans;
}
