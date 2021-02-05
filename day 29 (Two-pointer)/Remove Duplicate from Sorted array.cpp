//naive:- create a hash_set to store unique values and then replace the values of hash set to the array values.

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        int i,j=0,count=0;
        for(i=1;i<arr.size();i++)
        {
            if(arr[i]!=arr[j])
            {
               j++;
                swap(arr[i],arr[j]);
            }
        }
        return j+1;
    }
};
