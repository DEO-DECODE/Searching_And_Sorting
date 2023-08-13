//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int S1, int S2, int N){
        // code here
        int lo = 1, hi = 1e9, ans=INT_MAX;
    while (lo<=hi)
    {
        int mid=(lo+hi)/2;
        if((mid/S1+mid/S2)>=N){
            ans=min(ans, mid);
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
