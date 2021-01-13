#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
vector<int>vtt;
    vector<int>dfs(vector<int> adj[],int v,int s,bool visited[])
    {
        vtt.push_back(s);
        visited[s]=true;
        
        for(int k : adj[s])
        {
            if(visited[k]==false)
            dfs(adj,v,k,visited);
        }
        return vtt;
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    bool visited[V];
	    vector<int>ans;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            ans=dfs(adj,V,i,visited);
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
