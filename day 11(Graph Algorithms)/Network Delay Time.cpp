//leetcode 743

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        int distance[n+1];
        for(int i=1;i<=n;i++)
            distance[i]=INT_MAX;
        for(auto it: times)
        {
            adj[it[0]].push_back(make_pair(it[2],it[1]));
        }
        //adjacency list done
        int inf=INT_MAX;
        set<pair<int,int>> stt;
        stt.insert(make_pair(0,k));
        distance[k]=0;
        
        
        while(!stt.empty())
        {
            pair<int,int> curr=*(stt.begin());
            stt.erase(stt.begin());
            
            for(auto it: adj[curr.second])
            {
                int weight=(it.first);
                int node=(it).second;
                if(distance[node]>distance[curr.second]+weight)
                {
                    if(distance[node]!=inf)
                    {
                        stt.erase(stt.find(make_pair(distance[node],node)));
                    }
                    distance[node]=distance[curr.second]+weight;
                    stt.insert(make_pair(distance[node],node));
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            if(distance[i]==INT_MAX){
                return -1;
            }else{
                ans=max(ans,distance[i]);
            }
        return ans;
        // return distance[n];
    }
};
