//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    
    
    long long int  first_occur(vector<long long> v, long long x)
    {
        long long int start = 0;
        long long int end = v.size()-1;
        long long int f_occure = -1;
        
        while(start <= end)
        {
            long long int mid = start + (end-start)/2;
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
    
    long long int last_occur(vector<long long> v, long long x)
    {
        long long int start = 0;
        long long int end = v.size()-1;
        long long int l_occure = -1;
        
        while(start <= end)
        {
            long long int mid = start + (end-start)/2;
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
    
    
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long,long> p;
        p.first = (long)first_occur(v,x);
        p.second = (long)last_occur(v,x);
        
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends