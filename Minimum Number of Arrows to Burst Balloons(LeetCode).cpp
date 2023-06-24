#include <bits/stdc++.h>
using namespace std;
// Minimum Number of Arrows to Burst Balloons(LeetCode)
bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[1] != v2[1])
    {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), cmp);
    int numShots=0;
    int lastEnding=-1;
    int i=0, n=points.size();
    while (i<n)
    {
        if(points[i][0]>lastEnding){
            numShots++;
            lastEnding=points[i][1];
        }
        i++;
    }
    return numShots;
}
