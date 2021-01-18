//code is reffered from TECH-DOSE YouTube Channel

#include<bits/stdc++.h>
using namespace std;

struct node {		//struct for disjoint set
	int parent;
	int rank;
};
struct Edge {		//struct for kruskal
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;
//FIND operation
int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{

	//UNION by RANK
	if(dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)		//comparator function used in sorting
{
	return a.wt < b.wt;
}

void Kruskals(vector<Edge>& edge_List,int V,int E)
{
	sort(edge_List.begin(),edge_List.end(),comparator);

	int i=0,j=0;
	while(i<V-1 && j<E)
	{
		int fromP = find(edge_List[j].src);	//FIND absolute parent of subset
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP)
		{	++j;	continue;	}

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
		mst.push_back(edge_List[j]);
		++i;
	}
}
//Display the formed MST
void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for(int i=0;i<E;++i)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	Kruskals(edge_List,V,E);
	printMST(mst);
	
	return 0;
}
