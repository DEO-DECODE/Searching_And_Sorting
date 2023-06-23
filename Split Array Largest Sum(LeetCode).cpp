#include <bits/stdc++.h>
using namespace std;
// Split Array Largest Sum(LeetCode)
bool isPossible(vector<int> &nums, int midValue, int k)
{
    int n = nums.size();
    int curSum = 0, numPartitions = 0;
    for (int i = 0; i < n; ++i)
    {
        if (curSum += nums[i] > midValue)
        {
            curSum = 0;
            i--;
            numPartitions++;
        }
        return numPartitions <= k;
    }
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    // sort(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0), lo = 0;
    if (k == 1)
        return hi;
    int ans = hi;
    k--;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (isPossible(nums, mid, k))
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}
