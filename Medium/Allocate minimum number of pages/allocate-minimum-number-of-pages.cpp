//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool posible_solution(int A[], int N ,int M,int mid)
    {
        int sum = 0;
        int count = 1;
        for(int i = 0;i<N;i++)
        {
            if (A[i] > mid)
            {
                return false;
            }
            
            
            if (sum + A[i] > mid)
            {   
                sum = A[i];
                count++;
                if (count > M)
                {
                    return false;
                }
            }
            else
            {
                sum += A[i];
            }
        }
        return true;
    }
    
    
    int binary_serach_space(int A[], int N, int M){
        int end = accumulate(A,A+N,0);
        int start = 0;
        // for (int i = 0;i < N;i++)
        // {
        //     end += A[i];
        // }
        int solution = -1;
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if (posible_solution(A,N,M,mid))
            {
                solution = mid;
                end = mid  - 1;
            }
            else
            {
                start = mid +1;
            }
        }
        return solution;
        
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        
        
        if (N < M)
        {
            return -1;
        }
        else
        {
            return binary_serach_space(A,N,M);
        }
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends