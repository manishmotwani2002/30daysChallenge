#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> adj,int v)
{
    int i,j,k,dist[v][v];
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        dist[i][j]=adj[i][j];
    }
    
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                 if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }
        }
    }
    //for print
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(dist[i][j]==10000000)
            cout<<"INF"<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int v,i,j;
	cin>>v;
// 	v=V;
	vector<vector<int>> adj;
	for(i=0;i<v;i++)
	{
	    vector<int> temp;
	    for(j=0;j<v;j++)
	    {
	        string element;
	        cin>>element;
	        if(element=="INF")
	       temp.push_back(10000000);
	        else
	        {
	            int n=stoi(element);
	            temp.push_back(n);
	        }
	    }
	    adj.push_back(temp);
	}
	floydWarshall(adj,v);
	}
	
}
