// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int arr[N+1][W+1],i,j;
        for(i=0;i<N+1;i++)
        {
            for(j=0;j<W+1;j++)
            {
                if(i==0 || j==0)
                {
                    arr[i][j]=0;
                }
                
            }
        }
        for(i=1;i<N+1;i++)
        {
            for(j=1;j<W+1;j++)
            {
                if(i==0 ||j==0)
                arr[i][j]=0;
                
                if(wt[i-1]<=j)
                {
                    arr[i][j]=max(val[i-1]+arr[i][j-wt[i-1]],arr[i-1][j]);
                }
                else
                arr[i][j]=arr[i-1][j];
            }
        }
        return arr[N][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
