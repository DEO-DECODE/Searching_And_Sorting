//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long int costToEqualize(int n, int h[], int cost[], int height)
    {
        long long int costTo = 0;
        for (int i = 0; i < n; ++i)
        {
            costTo += abs(h[i] - height) * cost[i];
        }
        return costTo;
    }
	long long int Bsearch(int n, int h[], int cost[]) 
	{ 
		// Your code goes here
		int lo = 0, hi;
    for (int i = 0; i < n; ++i)
        {
            hi = max(hi, h[i]);
        }
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            long long int costTo2 = costToEqualize(n, h, cost, mid);
            long long int costTo1 = costToEqualize(n, h, cost, mid - 1);
            long long int costTo3 = costToEqualize(n, h, cost, mid + 1);
            if (costTo2 <= costTo3 && costTo2 <= costTo1)
            {
                return costTo2;
            }
            else if ( costTo2 >= costTo1)
            {
                hi = mid - 1;
            }
            else if (costTo2 >= costTo3)
            {
                
                    lo = mid + 1;
                
            }
        }
        return -1;
	}
		 

};
	  



//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        int h[n], c[n];
        for(int i=0; i<n; i++)
            cin>>h[i];
        
        for(int i=0; i<n; i++)
            cin>>c[i];
            
        
        

        Solution ob;
		cout << ob.Bsearch(n,h,c);
        
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends
