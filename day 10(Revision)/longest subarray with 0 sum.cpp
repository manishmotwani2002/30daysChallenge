#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int arr[], int n)
{
    int sum=0,max=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            max=i+1;
        }
        else
        {
            if(mpp.find(sum)!=mpp.end() )
            {
                auto itr=mpp.find(sum);
                int temp=i-itr->second;
                if(temp>max)
                {
                    max=temp;
                }
            }
            else
            {
                mpp[sum]=i;
            }
        }
    }
    return max;
}

