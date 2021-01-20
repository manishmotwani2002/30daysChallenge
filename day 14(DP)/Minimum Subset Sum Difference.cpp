#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	vector<int> subsetSum(int nums[],int sum,int n) {
	    vector<int> vtt;
        int i,j;
        bool arr[n+1][sum+1];
        
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    arr[i][j]=false;
                }
                if(j==0)
                {
                    arr[i][j]=true;
                }
                
            }
        }
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    arr[i][j]=(arr[i-1][j-nums[i-1]]) || (arr[i-1][j]);
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        for(j=0;j<sum+1;j++)
        {
            if(arr[n][j]==true)
            vtt.push_back(j);
        }
        return vtt;
    }
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum=0,i,j,ans=INT_MAX;;
	    for(i=0;i<n;i++)
	    sum+=arr[i];
	    
	    vector<int> temp=subsetSum(arr,sum,n);
	    for(i=0;i<temp.size();i++)
	    {
	       // if(temp[i]==true)
	       // {
	            int diff=abs(sum-2*temp[i]);
	            ans=min(ans,diff);
	       // }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
