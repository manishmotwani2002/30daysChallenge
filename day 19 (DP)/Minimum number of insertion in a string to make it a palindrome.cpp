class Solution {
public:
    int lcs(string s1, string s2,int x, int y){
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
    int minInsertions(string s) {
        int n=s.size();
        string rev;
	    rev=s;
	    reverse(rev.begin(),rev.end());
        int ans=lcs(s,rev,n,n);
	    return n-ans;
    }
};
