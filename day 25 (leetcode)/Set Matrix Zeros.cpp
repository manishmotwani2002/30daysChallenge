
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,count=0;
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<matrix[0].size();k++)
                    {
                        if(matrix[i][k]==0)
                        continue;
                        matrix[i][k]=-11;
                    }
                    for(int k=0;k<matrix.size();k++)
                    {
                        if(matrix[k][j]==0)
                        continue;
                        matrix[k][j]=-11;
                    }
                    // count++;
                    // break;
                }
                       
        }
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==-11)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};



