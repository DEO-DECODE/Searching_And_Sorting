#include <bits/stdc++.h>
using namespace std;
// Merge Intervals(LeetCode)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int endingPoint = intervals[0][1], startingPoint = intervals[0][0];
    int i = 0, n = intervals.size();
    vector<vector<int>> ans;
    while (i < n)
    {
        if (intervals[i][0] > endingPoint)
        {
            ans.push_back({startingPoint, endingPoint});
            startingPoint = intervals[i][0], endingPoint = intervals[i][1];
        }
        else
        {
            endingPoint = max(endingPoint, intervals[i][1]);
        }
        i++;
    }
    ans.push_back({startingPoint, endingPoint});
    return ans;
}
