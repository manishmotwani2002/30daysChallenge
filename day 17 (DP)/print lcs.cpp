//printing longest common subsequence
#include<bits/stdc++.h>
using namespace std;
void printLCS(string s1,string s2,int x,int y)
{
	int arr[x+1][y+1],i,j;
	for(i=0;i<x+1;i++)
	{
		arr[i][0]=0;
	}
	for(j=0;j<y+1;j++)
	{
		arr[0][j]=0;
	}
	
	for(i=1;i<x+1;i++)
	{
		for(j=1;j<y+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			arr[i][j]=1+arr[i-1][j-1];
			else
			{
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	//matrix formed
	
	string str;
	
	i=x;
	j=y;
	
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			str.push_back(s1[i-1]);
			i--;
			j--;	
		}
		else if(arr[i-1][j]>arr[i][j-1])
		{
			i--;
		}
		else
		j--;
	}
	reverse(str.begin(),str.end());
	cout<<str;
}

int main()
{
	int x,y;
	string s1,s2;
	cin>>s1>>s2;
	cin>>x>>y;
	printLCS(s1,s2,x,y);
	return 0;
}
