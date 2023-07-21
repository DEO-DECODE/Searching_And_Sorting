//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
    int ans = 0;
    sort(arr, arr+n , greater<int>());
    // for(int i=0; i<n; ++i){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int i=0;
    while (i<n)
    {
        if((i+1<n)&&(arr[i]-arr[i+1]<k)){
            ans+=(arr[i]+arr[i+1]);
            i++;
        }
        i++;
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends
