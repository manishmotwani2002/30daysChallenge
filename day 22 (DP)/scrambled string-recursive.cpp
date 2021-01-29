class Solution {
public:
    bool solve(string a,string b)
    {
        if(a.compare(b)==0)
            return true;
       
        int n=a.length();
        bool key=false;
        for(int i=1;i<=n-1;i++)
        {
            if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true)
            {
                return true;   
            }
            if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true)
            {
                return true;   
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);   
    }
};
