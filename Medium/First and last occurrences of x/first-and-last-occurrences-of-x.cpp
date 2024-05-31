//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int first_occur(int v[],int n,int x)
    {
        int start = 0;
        int end = n-1;
        int f_occure = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if (v[mid] == x)
            {
                f_occure = mid;
                end  = mid - 1;
            }
            else if (v[mid] < x)
            {
                start = mid +1;
            }
            else
            {
                end = mid -1;
            }
        }
        return f_occure;
    }
    
    int last_occur(int v[],int n,int x)
    {
        int start = 0;
        int end = n-1;
        int l_occure = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if (v[mid] == x)
            {
                l_occure = mid;
                start  = mid + 1;
            }
            else if (v[mid] < x)
            {
                start = mid +1;
            }
            else
            {
                end = mid -1;
            }
        }
        return l_occure;
    }
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>vect;
        
        vect.push_back(first_occur(arr,n,x));
        vect.push_back(last_occur(arr,n,x));
        
        return vect;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends