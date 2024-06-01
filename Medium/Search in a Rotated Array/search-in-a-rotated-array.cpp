//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
   int binary(int nums[], int target,int start,int end)
    {
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if (nums[mid] == target)
            {
                return mid;
            }
            else if ( nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
  
  int find_pivot(int nums[],int start,int end)
    {
        int n = end + 1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (start == end)
            {
                return start;
            }
            //////////////
            
            if (mid+1 < n && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            /////////////
            if (nums[start] > nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
 
        }

        return -1;
    }
  
  
  
  
    int search(int A[], int l, int h, int key) {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        int ans = -1;
        
        int pivot = find_pivot(A,l,h);
        
        if (key >= A[0] && key <= A[pivot])
        {
            ans = binary(A,key,0,pivot);
        }
        else
        {
            ans = binary(A,key,pivot + 1,h);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends