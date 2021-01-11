						/************** leetcode 658***************/
						
//Task:- find the K closest elements in a given sequence wrt given key						

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>p1;
        vector<int>vtt;
        for(int i=0;i<arr.size();i++)
        {
            int diff=abs(x-arr[i]);
            pair<int,int>pp;
            pp=make_pair(diff,arr[i]);
            
            p1.push(pp);
            if(i>k-1)
            {
                p1.pop();
            }
        }
        while(!p1.empty())
        {
            pair<int,int>dummy=p1.top();
            vtt.push_back(dummy.second);
            p1.pop();
        }
        sort(vtt.begin(),vtt.end());
        return vtt;
    }
};
