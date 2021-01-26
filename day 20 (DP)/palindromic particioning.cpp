// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    bool isPalindrome(string str,int i,int j)
    {
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
        
        int min=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int ans=1+solve(str,i,k)+solve(str,k+1,j);
            
            if(ans<min)
            min=ans;
        }
        return min;
    }
    int palindromicPartition(string str)
    {
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
