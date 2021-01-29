#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int arr[11][51];
int solve(int n,int k)
{
    if(k==0 || k==1)
    return k;
    if(n==1)
    return k;
    
    if(arr[n][k]!=-1)
    return arr[n][k];
    
    int mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        int temp=1+max(solve(n-1,i-1),solve(n,k-i));
        mini=min(mini,temp);
    }
    return arr[n][k]=mini;
}
int eggDrop(int n, int k) 
{
    memset(arr,-1,sizeof(arr));
    return solve(n,k);
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
