class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int min=INT_MAX;
        int profit=0,max=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            profit=abs(min-prices[i]);
            if(profit>max)
            {
                max=profit;
            }
        }
        return max;
    }
};


