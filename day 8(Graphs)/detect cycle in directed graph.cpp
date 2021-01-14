//detect cycle in directed graph- practised on GFG

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool dfs(vector<int> adj[],int s,bool visited[],bool recur[])
    {
        visited[s]=true;
        recur[s]=true;
        for(int k: adj[s])
        {
            if(visited[k]==false&&dfs(adj,k,visited,recur)==true)
            return true;
            else if(recur[k]==true)
            return true;
        }
        recur[s]=false;
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
	   bool visited[V];
	   int i;
	   bool recur[V];
	   for(i=0;i<V;i++)
	   visited[i]=false;
	   for(i=0;i<V;i++)
	   recur[i]=false;
	   
	   for(i=0;i<V;i++)
	   {
	       if(visited[i]==false&&dfs(adj,i,visited,recur)==true)
	       return true;
	   }
	   return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
