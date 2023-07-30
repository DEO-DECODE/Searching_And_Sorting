#include <bits/stdc++.h>
using namespace std;
bool minTowers(vector<int> &houses, int mid, int k)
{
    int towers = 0;
    int ind = 0, n = houses.size();
    while (ind < n)
    {
        int nextPos1 = houses[ind] + k;
        while (ind < n && houses[ind] <= nextPos1)
        {
            ind++;
        }
        ind--;
        towers++;
        int nextPos2 = houses[ind] + k;
        while (ind < n && houses[ind] <= nextPos2)
        {
            ind++;
        }
    }
    return towers <= mid;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> houses(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
    int lo=0, hi=n;
    int ans=n;
    while (lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(minTowers(houses, mid, k)){
            ans=min(ans, mid);
            hi=mid-1;
        }
        else lo=mid+1;
        
    }
    cout<<ans;
    
}
