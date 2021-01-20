//leetcode 416(extension of subset sum problem)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),i,sum=0,j;
        for(i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sum=sum/2;
        bool arr[n+1][sum+1];
        
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    arr[i][j]=false;
                }
                if(j==0)
                {
                    arr[i][j]=true;
                }
                
            }
        }
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    arr[i][j]=(arr[i-1][j-nums[i-1]]) || (arr[i-1][j]);
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        return arr[n][sum];
    }
};
