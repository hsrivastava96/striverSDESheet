class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size(), max = 0, diff = 0, min = prices[0];
        
        if(n == 1)
            return 0;
        for(int i = 1; i < n; i++)
        {
            if(prices[i] < min)
                min = prices[i];
            else
            {
                diff = prices[i] - min;
                if(diff > max)
                    max = diff;
            }
        }
        return max;
    }
};