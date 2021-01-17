#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	void revDFS(vector<int> adj[],bool visited[],int i)
	{
	    visited[i]=true;
	    for(auto it: adj[i])
	    {
	         if(visited[it]==false)
	            revDFS(adj,visited,it);
	    }
	   
	}
	void dfs(vector<int> adj[],bool visited[],int s,stack<int>&stt)
	{
	    visited[s]=true;
	    for(int i:adj[s])
	    {
	        if(visited[i]==false)
	        dfs(adj,visited,i,stt);
	    }
	    stt.push(s);
	}
    int kosaraju(int V, vector<int> adj[]) {
        int i,count=0;
        //apply dfs and form a stack
        stack<int>stt;
        bool visited[V];
        for(i=0;i<V;i++)
        visited[i]=false;
        
        for(i=0;i<V;i++)
        {
            if(visited[i]==false)
            dfs(adj,visited,i,stt);
        }
        //now reverse the nodes of the graph
        vector<int> grev[V];
        for(int i=0;i<V;i++)
        {
            for(auto j=adj[i].begin();j!=adj[i].end();j++)
            {
                grev[*j].push_back(i);
            }
        }
        //reinitailize the visited array
        for(i=0;i<V;i++)
        visited[i]=false;
        //clear the stack and apply dfs
        while(!stt.empty())
        {
            int curr=stt.top();
            stt.pop();
            if(visited[curr]==false)
            {
                count++;
                revDFS(grev,visited,curr);
            }
        }
        return count;
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
