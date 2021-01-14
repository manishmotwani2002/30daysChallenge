//detect cycle in undirected graph- practised on GFG

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool dfs(vector<int> adj[],int parent,int s,int visited[])
    {
        visited[s]=true;
        for(int k: adj[s])
        {
            if(visited[k]==false)
            {
                if(dfs(adj,s,k,visited)==true)
	            return true;
            }
            else if(k!=parent)
            return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    int visited[V];
	    int i;
	    for(i=0;i<V;i++)
	    visited[i]=false;
	    
	    for(i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(dfs(adj,-1,i,visited)==true)
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
