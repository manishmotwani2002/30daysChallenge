/*********************** leetcode 973 ******************/

// K Closest Points to Origin
class Solution {
public:
    int distance(vector<int>& vt)
    {
        return (vt[0]*vt[0]) + (vt[1]*vt[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,vector<int>>>q1;
        vector<vector<int>>vtt;
        for(int i=0;i<points.size();i++)
        {
            // vector<int>temp=points[i];
            // pair<int,int>dummy;
            // dummy=make_pair(points[i][0],points[i][1]);
            int distt=distance(points[i]);
            
            q1.push({distt,points[i]});            
            if(q1.size()>K)
            {
                q1.pop();
            }
        }
        while(!q1.empty())
        {
            pair<int,vector<int>> temp=q1.top();   
            vtt.push_back(temp.second);
            q1.pop();
        }
        return vtt;
    }
};
