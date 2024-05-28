//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int funtion(vector<int>& arr,int mid)
  {
      int total=0;
      for (int i = 0; i<arr.size();i++)
      {
          total += ceil((double)arr[i] / (double)mid);
      }
      return total;
  }
  
  
  
  int binary(vector<int>& arr,int start,int end,int target)
  {
      
      while(start <= end)
      {
          int mid = (start + end)/2;
        //   cout<<start<<" "<<mid << " "<<end<<endl;
        //   cout<<mid<<" "<< funtion(arr,mid) <<" "<<target<<endl;
          if (funtion(arr,mid) <= target)
          {
              end = mid -1;
          }
          else
          {
              start = mid +1;
          }
          
          
         
      }
      
      return start;
  }
  
  
  
  
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int min = INT_MAX;
        int max = INT_MIN;
        int j = N;
        while (j>=0){
            if (max < piles[j])
            {
                max = piles[j];
            }
            if (min > piles[j])
            {
                min = piles[j];
            }
            
            j--;
        }
        
        
        return binary(piles,min,max,H);
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends