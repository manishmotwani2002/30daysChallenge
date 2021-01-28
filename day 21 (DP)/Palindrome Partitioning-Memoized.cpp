// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





// User function Template for C++

class Solution{
public:
    int arr[501][501];
    
    bool isPalindrome(string str,int i,int j)
    {
        if(i>=j)
        return true;
        // int n=j-i;
        int start=i;
        int end=j;
        while(start<end)
        {
            if(str[start]!=str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int solve(string str,int i,int j)
    {
        if(i>=j)
        return 0;
        
        if(isPalindrome(str,i,j))
        return 0;
        
        if(arr[i][j]!=-1)
        return arr[i][j];
        
        int min=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int ans=solve(str,i,k)+solve(str,k+1,j)+1;
            if(ans<min)
            min=ans;
        }
        return arr[i][j]=min;
    }
    int palindromicPartition(string str)
    {
        memset(arr,-1,sizeof(arr));
        return solve(str,0,str.size()-1);
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
