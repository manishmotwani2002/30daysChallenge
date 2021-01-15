//topological sorting using BFS
#include<bits/stdc++.h>
using namespace std;
void topoSort(vector<int> adj[],int V,int indegree[])
{
	int i;
	queue<int>q1;
	vector<int>vtt;
	//this step is to push the vertices into the queue with indegree 0
	for(i=0;i<V;i++)
	{
		if(indegree[i]==0)
		{
			q1.push(i);
		}
	}
	
	//check for cyclic graph
	int count=0;
	
	//now we will perform BFS on these vertices
	while(!q1.empty())
	{
		int curr=q1.front();
		q1.pop();
		vtt.push_back(curr);
		
		//we only push that values whose indegree is 0, i.e all above tasks are done and dependency is 0
		for(auto it=adj[curr].begin();it!=adj[curr].end();it++)
		{
			if(--indegree[*it]==0)
			q1.push(*it);	
		}
		count++;
	}
	//check for cycle
	if(count!=V)
	cout<<"the grpah is cyclic so topological sort can't be performed\n";
	else
	{
		for(auto itr=vtt.begin();itr!=vtt.end();itr++)
		cout<<*itr<<" ";
		cout<<endl;
	}
	
}
int main()
{
	int V,E,i;
	cin>>V>>E;
	vector<int> adj[V];
	int indegree[V]={0};
	for(i=0;i<E;i++)
	{
		//addEdge implement
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	topoSort(adj,V,indegree);
	return 0;
}
