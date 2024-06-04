//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    bool isposible(int arr[], int n, int k,long long int mid)
    {
        long long int as = 0;
        for (int i = 0;i<n;i++)
        {   if (arr[i] > mid)
            {
                return false;
            }
        
            as = as + arr[i];
            if (as > mid)
            {
                as = arr[i];
                k--;
                if(k == 0)
                {
                    break;
                }
            }
            
        }
        
        return k > 0;
    }
    
    
  
    long long minTime(int arr[], int n, int k)
    {
        long long int ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans = ans + arr[i];
        }
        
        long long int start = 0;
        long long int end = ans;
        
        ans = -1;
    
        long long int mid = start + (end - start)/2;
        
        while(start<=end)
        {
            if (isposible(arr,n,k,mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        
        return (long long)ans;
        
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