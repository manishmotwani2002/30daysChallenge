						/************** leetcode 378***************/
						
//Kth Smallest Element in a Sorted(Row-wise) Matrix,, to sort the array "nlog(n)" is required complexity and with the help of heaps we can solve it in nlog(k) where k index given***********/						

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i,j;
        priority_queue<int>q1;
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix.size();j++)
            {
                q1.push(matrix[i][j]);
                if(q1.size()>k)
                {
                    q1.pop();
                }
            }
        }
        return q1.top();
    }
};
