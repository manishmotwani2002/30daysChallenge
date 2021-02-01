
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low,mid,high,i;
        high=nums.size()-1;
        low=mid=0;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    {
                        swap(nums[low],nums[mid]);
                        low++;
                        mid++;
                        break;
                    }  
                case 1:
                    {
                        mid++;
                        break;
                    }
                case 2:
                    {
                        swap(nums[high],nums[mid]);
                        high--;
                        break;

                    }
            }
        }
    }
};


