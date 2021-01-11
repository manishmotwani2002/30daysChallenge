#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    priority_queue <int, vector<int>, greater<int>> q1;  
	    int n,k,element,i,temp=0;
	    cin>>n>>k;
	    int arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(i=0;i<k;i++)
	    {
	        q1.push(arr[i]);
	    }
	    for(i=k;i<n;i++)
	    {
	        arr[temp]=q1.top();
	        q1.pop();
	        q1.push(arr[i]);
	        temp++;
	    }
	    while(!q1.empty())
	    {
	        arr[temp]=q1.top();
	        q1.pop();
	        temp++;
	    }
	    for(i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
