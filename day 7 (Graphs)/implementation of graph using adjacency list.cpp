//creation of a graph using adjacency list representation
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[],int u,int v)
{
	arr[u].push_back(v);
	arr[v].push_back(u);
}
void printGraph(vector<int> arr[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(auto it=arr[i].begin();it!=arr[i].end();it++) {
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int v,u;
	cin>>v;
	vector<int> arr[v];
	addEdge(arr, 0, 1); 
    addEdge(arr, 0, 4); 
    addEdge(arr, 1, 2); 
    addEdge(arr, 1, 3); 
    addEdge(arr, 1, 4); 
    addEdge(arr, 2, 3); 
    addEdge(arr, 3, 4); 
	printGraph(arr,v);
	return 0;
}
