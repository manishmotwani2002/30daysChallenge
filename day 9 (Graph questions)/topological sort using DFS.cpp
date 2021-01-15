//topological sort using DFS in a directed graph
#include<bits/stdc++.h>
using namespace std;
void topoImplement(vector<int> adj[],int V,bool visited[],int s,stack<int>& stt)
{
	visited[s]=true;
	for(int k: adj[s])
	{
		if(visited[k]==false)
		{
			topoImplement(adj,V,visited,k,stt);
		}
	}
	stt.push(s);
}
void topoSort(vector<int> adj[],int V)
{
	int i;
	stack<int>stt;
	//creation of a visited array
	bool visited[V];
	for(i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			topoImplement(adj,V,visited,i,stt);
		}
	}
	
	//for printing
	while(!stt.empty())
	{
		cout<<stt.top()<<" ";
		stt.pop();
	}
}
int main()
{
	int V,E,i;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		//addEdge implement
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	topoSort(adj,V);
	return 0;
}
