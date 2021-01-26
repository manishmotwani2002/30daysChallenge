#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int i,j,sum=0;
	    
	    if(M==1 && V%coins[0]!=0)
	    return -1;
	    
	    int arr[M+1][V+1];
	    for(i=0;i<M+1;i++)
	    {
	        arr[i][0]=0;
	    }
	    for(i=0;i<V+1;i++)
	    {
	        arr[0][i]=INT_MAX-1;
	    }
	    //initialization done
	    for(i=1;i<M+1;i++)
	    {
	        for(j=1;j<V+1;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                arr[i][j]=min(arr[i-1][j],1+arr[i][j-coins[i-1]]);
	            }
	            else
	            arr[i][j]=arr[i-1][j];
	        }
	    }
	    if(arr[M][V]==INT_MAX-1)
	    return -1;
	    return arr[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
