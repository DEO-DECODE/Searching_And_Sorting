#include <bits/stdc++.h>
using namespace std;
// Search in Rotated Sorted Array(LeetCode)
int search(vector<int> &nums, int target)
{
    int n = nums.size(), lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // letf part sorted.
        if (nums[lo] <= nums[mid])
        {
            if (target >= nums[lo] && target <= nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        // right part sorted
        else
        {
            if (target <= nums[hi] && target >= nums[mid])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    return -1;
}
