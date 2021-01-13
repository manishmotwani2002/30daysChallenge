#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[],int s){
	    int i;
	    vector<int>vtt;
	    queue<int>q1;
	    bool visited[V+1];
	    for(i=0;i<V;i++)
	    visited[i]=false;
	    
	    visited[s]=true;
	    q1.push(s);
	    
	    while(!q1.empty())
	    {
	        int front=q1.front();
	        q1.pop();
	        vtt.push_back(front);
	       // cout<<front<<" ";
	        for(int k: adj[front])
	        {
	            if(visited[k]==false)
	            {
	                visited[k]=true;
	                q1.push(k);
	            }
	        }
	      
	    }
	    return vtt;
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
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj,0);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
