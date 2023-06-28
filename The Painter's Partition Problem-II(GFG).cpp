//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(long long time, int arr[], int n, int k)
{
    int curSum = 0, i = 0;
    while (i < n && k)
    {
        if (curSum + arr[i] > time)
        {
            curSum = 0;
            i--, k--;
        }
        else
        {
            curSum += arr[i];
        }
        i++;
    }
    return k >= 0 && i >= n;
}
long long minTime(int arr[], int n, int k)
{
    long long lo = 0, hi = 1e10, ans = 1e10;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (isPossible(mid, arr, n, k))
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
