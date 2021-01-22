//coin change maximum	leetcode 518

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //coins is the weight array
        //amount is the final weight of kanpsack
        int n=coins.size(),i,j;
        int arr[n+1][amount+1];
        for(j=0;j<amount+1;j++)
            arr[0][j]=0;
        for(j=0;j<n+1;j++)
            arr[j][0]=1;
        for(i=1;i<n+1;i++)
        {
            for(j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    arr[i][j]=arr[i][j-coins[i-1]]+arr[i-1][j];
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
        return arr[n][amount];
    }
};
