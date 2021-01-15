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
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i,v=N;
        vector<vector<int>> graph(v+1);
        for(auto it:dislikes)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        bool visited[v+1],result=true;
        int colour[v+1];
        for(i=1;i<=v;i++)
        {
            visited[i]=false;
        }
        for(i=1;i<=v;i++)
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
