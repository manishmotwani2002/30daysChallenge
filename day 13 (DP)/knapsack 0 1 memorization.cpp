#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends









int solve(vector<vector<int>>& vtt,int W, int wt[], int val[], int n)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(vtt[n][W]!=-1)
    {
        return vtt[n][W];
    }
    
    if(wt[n-1]<=W)
    {
        return vtt[n][W]=max(val[n-1]+solve(vtt,W-wt[n-1],wt,val,n-1), solve(vtt,W,wt,val,n-1));
    }
    else
    {
        return vtt[n][W]=solve(vtt,W,wt,val,n-1);   
    }
}

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   vector<vector<int>> vtt;
   for(int i=0;i<n+1;i++)
   {
       vector<int> temp;
       for(int j=0;j<W+1;j++)
       {
           temp.push_back(-1);
       }
       vtt.push_back(temp);
   }
   return solve(vtt,W,wt,val,n);
}








// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
