//bfs of disconnected-undirected grpah
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[],int u,int v)
{
	arr[u].push_back(v);
	arr[v].push_back(u);
}
void BFS(vector<int> adj[],int i,int v,bool visited[])
{
	queue<int>q1;
	visited[i]=true;
	q1.push(i);
	
	while(!q1.empty())
	{
		int curr=q1.front();
		q1.pop();
		cout<<curr<<" ";
		for(int k: adj[curr])
		{
			if(visited[k]==false)
	            {
	                visited[k]=true;
	                q1.push(k);
	            }
		}
	}
}
void BFSdis(vector<int> adj[],int v)
{
	int i;
	bool visited[v];
	for(i=0;i<v;i++)
	visited[i]=false;
	for(i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			BFS(adj,i,v,visited);
		}
	}
}
int main()
{
	int v=5;
	vector<int> adj[v];
	addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4);
	BFSdis(adj,v); 
	return 0;
}
