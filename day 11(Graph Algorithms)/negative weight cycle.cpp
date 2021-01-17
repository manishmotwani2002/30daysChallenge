
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edjes){
	    // Code here
	    int distance[n],i;
	    for(i=0;i<n;i++)
	    distance[i]=INT_MAX;
	    distance[0]=0;
	    
	    for(int j=1;j<=n-1;j++)
	    {
	        for(i=0;i<n;i++)
	        {
                int src=edjes[i][0];
    	        int dest=edjes[i][1];
    	        int weight=edjes[i][2];
    	        
    	        if(distance[src]!=INT_MAX && distance[src]+weight<distance[dest])
    	        distance[dest]=distance[src]+weight;	            
	        }

	    }
	    //for negative cycle
	     for(i=0;i<n;i++)
	    {
	        int src=edjes[i][0];
	        int dest=edjes[i][1];
	        int weight=edjes[i][2];
	        
	        if(distance[src]!=INT_MAX && distance[src]+weight<distance[dest])
	        return 1;
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
