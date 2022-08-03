    /*
        Algo:
        So, for 1 step
    */


    int countStair(int n, unordered_map<int, int> &dp)
    {
        if(dp.find(n) != dp.end())
            return dp[n];
        
        dp[n] = (countStair(n-1, dp) + countStair(n-2, dp))%1000000007; 

        return dp[n];
    }
    
    int countWays(int n)
    {
        // your code here
        unordered_map<int, int> dp;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        int numberOfWays = countStair(n, dp);
        return numberOfWays;
    }
