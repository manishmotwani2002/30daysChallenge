						/************** leetcode 347***************/
						
//Top K Frequent Elements,,we have to return the "K" frequent numbers in the given sequence						


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>vtt;
          priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q1;  
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            q1.push({it->second,it->first});
            if(q1.size()>k)
            {
                q1.pop();
            }
        }
        while(!q1.empty())
        {
            pair<int,int>pp;
            pp=q1.top();
            vtt.push_back(pp.second);
            q1.pop();
        }
        return vtt;
    }
};
