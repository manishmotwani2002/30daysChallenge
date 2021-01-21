class Solution {
public:
    int countNoOfSubsets(vector<int>& nums,int s,int n)
    {
        int arr[n+1][s+1],i,j;
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<s+1;j++)
            {
                if(i==0)
                {
                    arr[i][j]=0;
                }
                if(j==0)
                {
                    arr[i][j]=1;
                }
                
                if(i!=0 && j!=0)
                    arr[i][j]=0;
            }
        }
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<s+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    arr[i][j]=arr[i-1][j-nums[i-1]] + arr[i-1][j];
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        return arr[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0,i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum<S || (sum+S)%2!=0)
            return 0;
        int s1,s2;
        s1=(sum+S)/2;
        return countNoOfSubsets(nums,s1,n);
    }
};
