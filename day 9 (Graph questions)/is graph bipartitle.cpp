/****************** leetcode 785 ********************/

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int s,bool visited[],int colour[],int c)
    {
        visited[s]=true;
        colour[s]=c;
        for(int k:graph[s])
        {
            if(visited[k]==false)
            {
                if(dfs(graph,k,visited,colour,1^c)==false)
                    return false;
            }
            else if(colour[s]==colour[k])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int i,v=graph.size();
        
        bool visited[v],result=true;
        int colour[v];
        for(i=0;i<v;i++)
        {
            visited[i]=false;
        }
        for(i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(graph,i,visited,colour,0)==false)
                {
                    result=false;
                    break;
                }
            }
        }
        return result;
    }
};
