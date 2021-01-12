/***************** GFG() *********************/

//our task is to connect the given ropes to find the minimum cost

#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long minCost(long long arr[], long long n) {
    priority_queue <long long, vector<long long>, greater<long long>> q1;
    for(long long i=0;i<n;i++)
    {
        q1.push(arr[i]);
    }
    long long sum=0;
    while(!q1.empty())
    {
        if(q1.size()==1)
        {
            break;
        }
        long long first=q1.top();
        q1.pop();
        long long second=q1.top();
        q1.pop();
        sum+=first+second;
        q1.push(first+second);
    }
    return sum;
}

