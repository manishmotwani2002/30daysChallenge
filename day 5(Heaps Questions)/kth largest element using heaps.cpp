						/************** leetcode 215***************/
						
//Kth largest element of array,,, implemented using minHeap to reduce the time complexity***********/						

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> g;  
        for(int i=0;i<nums.size();i++)
        {
            g.push(nums[i]);
            if(g.size()>k)
            {
                g.pop();
            }
        }
        return g.top();
    }
};
