class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,count,n=nums.size(),temp=0,ans=0;
        unordered_set<int>s1;
        for(i=0;i<n;i++)
        {
            s1.insert(nums[i]);
        }
        for(i=0;i<n;i++)
        {
            int x=0;
            count=0;
            if(s1.find(nums[i]-1)==s1.end())
            {
                count++;
                while(s1.find(nums[i]+1+x)!=s1.end())
                {
                    // cout<<nums[i]+x+1<<endl;
                    count++;
                    x++;
                }
                // // cout<<endl;
                // if(temp>count)
                // {
                //     ans=temp;
                // }
                // else if(temp<count)
                // {
                //     ans=count;
                // }
                // else
                // {
                //     if(count>ans)
                //     {
                //         ans=count;
                //     }
                // }
                // temp=count;
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
