						/************** leetcode 451***************/
						
//Sort Characters By Frequency					

class Solution {
public:
    string frequencySort(string s) {
        int i;
        string ans="";
        unordered_map<char,int>mpp;
        priority_queue<pair<int,char>>q1;
        for(i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        
        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            pair<int,char>pr;
            pr=make_pair(it->second,it->first);
            q1.push(pr);
        }
        
        while(!q1.empty())
        {
            pair<int,char>dummy=q1.top();
            while(dummy.first!=0)
            {
                ans.push_back(dummy.second);
                dummy.first=dummy.first-1;
            }
            q1.pop();
        }
        return ans;
}
};
