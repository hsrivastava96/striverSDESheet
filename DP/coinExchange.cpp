/*
    Algo:
    Here, we are using Top Down DP or Memoization DP technique to solve and optimise this solution
    So basically, number of coins required for already existing coins will be = 1 for each existing coin
    Lets say we have [1,2,5]
    Then if target amount is 1,2, or 5 then our answer will be 1
    so we prepare a map:
    {1:1, 2:1, 5:1}
    Then,
    We call a recursive function to solve the problem with target, coins vector and map
    Then we check:
    if target is negative:
        this is the case when we choose a coin from coins which is bigger than required amount
        e.g. target = 3 and we choose 5 => this will make our target = -2
        So, in such cases we will return -1 directly
    if target is available in our DP map dataset
        then we simply return the number of coins required for the target as key in our map
    else
        we recursively call for each possible value as per our coin base in the given vector of coins and
        then after each backtrack we store the minimum number of coins required for each sub problem target
        in our dp map
        and return the coins needed for sub problem's  


*/


class Solution {
public:
    
    int exch(int target, vector<int> &coins, unordered_map<int, int> &m)
    {
        if(target < 0)
            return -1;
        if(m.find(target) != m.end())
            return m[target];
        else
        {
            int sum = 0, min = INT_MAX, rcvdCoins = 0;
            for(int i = 0; i < coins.size(); i++)
            {
                rcvdCoins = exch(target - coins[i], coins, m);
                
                if(rcvdCoins != -1)
                {
                    rcvdCoins+=1;
                    if(rcvdCoins < min)
                        min = rcvdCoins;
                }
            }
            if(min != INT_MAX)
                m[target] = min;
            else
                m[target] = -1;
            return m[target];
        }
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0)
            return 0;
        unordered_map<int, int> m;
        for(auto it:coins)
            m[it] = 1;
        
        int reqCoins = exch(amount, coins, m);
        
        // for(auto it: m)
        //     cout<<it.first<<"\t"<<it.second<<endl;
        return reqCoins;
    }
};