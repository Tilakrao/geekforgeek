//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isposible(vector<int> &stalls,int n, int k,int mid)
    {
        int last_cow_pos = stalls[0];
        int c= 1;
        
        for (int i =0;i<n;i++)
        {
            if(stalls[i] - last_cow_pos >=mid)
            {
                last_cow_pos = stalls[i];
                c++;
                if (c==k)
                {
                    return true;
                }
            }
        }
        return false;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int start = 0;
        int end = stalls[n-1]-stalls[0];
        int ans = -1;
        int mid = start + (end - start)/2;
        
        while(start <= end)
        {
            if (isposible(stalls,n,k,mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends