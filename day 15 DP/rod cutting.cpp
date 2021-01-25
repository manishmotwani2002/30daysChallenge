#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends

int dp[10004];
//Complete this function
int maxcut(int n,int x,int y,int z){
if(n==0)
return 0;
else if(n<0)
return INT_MIN;
else if(dp[n]!=-1)
return dp[n];
else
return dp[n]=max(1+maxcut(n-x,x,y,z),max(1+maxcut(n-y,x,y,z),1+maxcut(n-z,x,y,z)));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
memset(dp,-1,sizeof(dp));
int a= maxcut(n,x,y,z);
if(a<0)
return 0;
else
return a;
}
