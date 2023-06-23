#include <bits/stdc++.h>
using namespace std;
// Queue Reconstruction by Height(leetcode)
bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[0] != v2[0])
        return v1[0] > v2[0];
    return v1[1] < v2[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    int n = people.size();
    vector<vector<int>> ans;
    sort(people.begin(), people.end());
    for (auto vec : people)
    {
        ans.insert(ans.begin() + vec[1], vec);
    }
    return ans;
}
