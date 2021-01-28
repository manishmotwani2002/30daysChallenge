#include<bits/stdc++.h>
using namespace std;

int t[1000][1000];

unordered_map<string, int> mp;

int balancedParenthesization(string s, int i, int j, bool val)
{
    // Base case
    if(i > j)
        return 0;
    if(i == j)
    {
        if(val)
            return (s[i] == 'T');
        return (s[i] == 'F');
    }
    
    string str = to_string(i);
    str.push_back(' ');
    str.append(to_string(j));
    str.push_back(' ');
    str.append(to_string(val));
    
    if(mp.find(str) != mp.end())
        return mp[str];
    
    // Main Code
    int answer = 0, lf, lt, rf, rt; 
    
    for(int k = i+1; k < j; k += 2)
    {
        lt = balancedParenthesization(s, i, k-1, true);
        lf = balancedParenthesization(s, i, k-1, false);
        rt = balancedParenthesization(s, k+1, j, true);
        rf = balancedParenthesization(s, k+1, j, false);
        
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
    
    mp[str] = answer;
    return answer;
}

int main()
{
    memset(t, -1, sizeof(t));
    
    string str = "T|T&F^T";
    cout<<balancedParenthesization(str, 0, str.size()-1, true);
    
    return 0;
}




