#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence
int solve(vector<vector<int>>& arr,int x, int y, string s1, string s2)
{
    if(x==0 || y==0)
    return 0;
    
    if(arr[x][y]!=-1)
    return arr[x][y];
    
    if(s1[x-1]==s2[y-1])
    {
         arr[x][y]=1+solve(arr,x-1,y-1,s1,s2);
          return arr[x][y];
    }
    else
    {
        arr[x][y]=max(solve(arr,x-1,y,s1,s2),solve(arr,x,y-1,s1,s2));
        return arr[x][y];
    }
        
}
int lcs(int x, int y, string s1, string s2){
    //recursive approach
    int i,j;
    vector<vector<int>> arr;
    for(i=0;i<x+1;i++)
    {
        vector<int> temp;
        for(j=0;j<y+1;j++)
        {
            temp.push_back(-1);
        }
        arr.push_back(temp);
    }
    return solve(arr,x,y,s1,s2);
}
