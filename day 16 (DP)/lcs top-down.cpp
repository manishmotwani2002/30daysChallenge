using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence
int lcs(int x, int y, string s1, string s2){
    //recursive approach
    int i,j;
    int arr[x+1][y+1];
    for(i=0;i<x+1;i++)
    arr[i][0]=0;
    for(j=0;j<y+1;j++)
    arr[0][j]=0;
    
    for(i=1;i<x+1;i++)
    {
        for(j=1;j<y+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[x][y];
}
