#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int arr[n+1][m+1],i,j,count=0,ans=0;
        for(i=0;i<n+1;i++)
        {
            arr[i][0]=0;
        }
        for(j=0;j<m+1;j++)
        {
            arr[0][j]=0;
        }
        //initialization done
        for(i=1;i<n+1;i++)
        {
            for(j=1;j<m+1;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    arr[i][j]=1+arr[i-1][j-1];
                    ans = max(ans, arr[i][j]);
                }
                else
                {
                    arr[i][j]=0;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
