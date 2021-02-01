class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i,j;
        vector<vector<int>>vtt;
        for(i=0;i<numRows;i++)
        {
            vector<int>vt;
            for(j=0;j<=i;j++)
            {
              if(j==0 || j==i)
              {
                  vt.push_back(1);
              }
              else
              {
                  vt.push_back(vtt[i-1][j-1]+vtt[i-1][j]);
              }
            }
            vtt.push_back(vt);
        }
        return vtt;
    }
};



