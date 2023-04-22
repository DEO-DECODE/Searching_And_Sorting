#include <bits/stdc++.h>
using namespace std;
// Heaters(LeetCode)
bool isPossible(vector<int> &houses, vector<int> &heaters, int radius)
{
    int i = 0, j = 0, numHeaters = 1, n = houses.size(), n1 = heaters.size();
    while (i < n)
    {
        if (j == n1)
            return false;
        if (abs(heaters[j] - houses[i]) <= radius)
        {
            i++;
        }
        else
        {
            // i--;
            numHeaters++;
            j++;
        }
        if (numHeaters > n1)
            return false;
    }
    return true;
}
int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int lo=0, hi=1e9, ans=1e9;
    while (lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(isPossible(houses, heaters, mid)){
            ans=min(ans, mid);
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}
