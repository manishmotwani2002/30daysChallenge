// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int solve(string s,int i,int j,bool val)
    {
    if(i > j)
        return 0;
    if(i == j)
    {
        if(val)
            return (s[i] == 'T');
        return (s[i] == 'F');
    }
    
    
    int answer = 0, lf, lt, rf, rt; 
    
    for(int k = i+1; k < j; k += 2)
    {
        lt = solve(s, i, k-1, true);
        lf = solve(s, i, k-1, false);
        rt = solve(s, k+1, j, true);
        rf = solve(s, k+1, j, false);
        
        if(s[k] == '&')
        {
            if(val)
                answer += lt * rt;
            else    
                answer += lf * rt + lt * rf + lf * rf;
        }
        
        else if(s[k] == '^')
        {
            if(val)
                answer += lf * rt + lt * rf;
            else
                answer += lt * rt + lf * rf;
        }
        
        else if(s[k] == '|')
        {
            if(val)
                answer += lt * rt + lt * rf + lf * rt;
            else
                answer += lf * rf;
        }
    }
    return answer;
}
    
    
    int countWays(int N, string S){
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
