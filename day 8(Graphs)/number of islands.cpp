/***************** leetcode 200 *******************/

//the logic is to traverse through the entire grid and check for '1', if '1' is present then we increment the count and make all connected components to '0' so that the loop will not run for that again and then return the count

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == '1') {
            grid[i][j] = 0;
            dfs(grid, i-1, j, m, n);
            dfs(grid, i+1, j, m, n);
            dfs(grid, i, j-1, m, n);
            dfs(grid, i, j+1, m, n);
        }
        else
            return;       
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m=grid.size(),n=grid[0].size(),count=0,i,j;
        
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};
