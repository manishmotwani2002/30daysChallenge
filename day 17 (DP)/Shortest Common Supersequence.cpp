//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
int lcs(char *X,char *Y,int m,int n)
{
    int arr[m+1][n+1],i,j;
    for(i=0;i<m+1;i++)
    arr[i][0]=0;
    for(j=0;j<n+1;j++)
    arr[0][j]=0;
    
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            arr[i][j]=1+arr[i-1][j-1];
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[m][n];
}
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    return m+n-lcs(X,Y,m,n);
}
