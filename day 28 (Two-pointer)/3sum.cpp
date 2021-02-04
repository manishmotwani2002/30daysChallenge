class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int start,end,sum,i;
        set<vector<int>>s1;
        int n=nums.size();
        for(i=0;i<n-2;i++)
        {
            
            start=i+1;
            end=n-1;
            while(start<end)
            {
                sum=nums[i]+nums[start]+nums[end];
                if(sum==0)
                {
                    s1.insert({nums[i],nums[start++],nums[end--]});
                    // end--;
                    // start++;
                }
                else if(sum<0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        for(auto it : s1)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};
