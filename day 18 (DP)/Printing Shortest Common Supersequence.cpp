#include <bits/stdc++.h> 
using namespace std; 
int static t[101][101];

int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int m,n;
	    cin>>m>>n;
	    string X,Y;
	    cin>>X>>Y;
	    for(int i=0;i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 || j==0)
	                t[i][j]=0;
	        }
	    }
	    
	    for(int i=1;i<m+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(X[i-1]==Y[j-1])
	                t[i][j]=1+t[i-1][j-1];
	            else 
	                t[i][j]=max(t[i][j-1],t[i-1][j]);
	        }
	    }
	    int i=m,j=n;
	    string s="";
	    while(i>0 && j>0){
	        if(X[i-1]==Y[j-1]){
	            s=s+X[i-1];
	            i--;
	            j--;
	        }     
	        else{
	            if(t[i-1][j]>t[i][j-1]){
	                s=s+X[i-1];
	                i--;
	                
	            }     
	            else{ 
	                s=s+Y[j-1];
	                j--;
	                
	            }      
	        }     
	    }
	    
	    while(i>0){
	        s=s+X[i-1];
	        i--;
	    }
	    
	    while(j>0){
	        s=s+Y[j-1];
	        j--;
	    }
	    reverse(s.begin(),s.end());
	    cout<<s<<endl;
	}
	
	return 0; 
} 

