/*
    Algo:
    Question says we have to travel to (n-1, n-1) then return to (0, 0)
    So, what if we simply run two times from (0, 0) to (n-1, n-1)

    Then this problem becomes two People travelling together at the same time.
    Then, we consider them in terms of (i1, j1) and (i2, j2)

    For our case there will be four combinations for any A and B
    Thus, i1 + j1 = i2 + j2

    So, instead of having a dp vector of 4 dimension, we can have it for 3D

    Thus, in our recursion we first check if current cell for both are valid or not
    If not, we return minimum possible value to help in finding max of all possible combinations

    Otherwise we check if any A has reached end or not (Here, we could have checked for B as well)
    Because to find max both will reach (n-1, n-1) at the same time
    
    Then we can have a dp of [i1][j1][j2] or [i1][j1][i2] or [i1][i2][j2] or [j1][i2][j2]
    because i1 + j1 = i2 + j2 

    Then we find max of all possible combinations and add the to our current sum 
    (It could be a sum or A/B in case botha re same cell)
    
    at the end return ans
*/

class Solution {
public:
    int max(int a, int b, int c, int d)
    {
        if(a >= b && a >= c && a >= d)
            return a;
        else if(b >= a && b >= c && b >= d)
            return b;
        else if(c >= a && c >= b && c >= d)
            return c;
        else
            return d;
    }
    
    int maxCherry(int i1, int j1, int i2, int j2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e9;
        if(i1 == n - 1 && j1 == n-1)
            return grid[i1][j1];
        
        if(dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];
        
        int val = 0, copyA = grid[i1][j1], copyB = grid[i2][j2];
        if(i1 == i2 && j1 == j2)
            val = grid[i1][j1];
        else
            val = grid[i1][j1] + grid[i2][j2];
        
        // Set current value to 0 for both A and B
        grid[i1][j1] = 0;
        grid[i2][j2] = 0;
        
        /* 4 combinations of paths: (aRight, bRight), (aRight, bDown), (aDown, bRight), (aDown, bDown)*/ 
        int p = maxCherry(i1, j1+1, i2, j2+1, n, grid, dp);
        int q = maxCherry(i1, j1+1, i2+1, j2, n, grid, dp);
        int r = maxCherry(i1+1, j1, i2, j2+1, n, grid, dp);
        int s = maxCherry(i1+1, j1, i2+1, j2, n, grid, dp);
        
        // reset both A and B current inexes to their original values
        grid[i1][j1] = copyA;
        grid[i2][j2] = copyB;

        val+=max(p, q, r, s);
        dp[i1][j1][i2] = val;
        return dp[i1][j1][i2];
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = maxCherry(0, 0, 0, 0, n, grid, dp);
        return (ans < 0)?0:ans;
    }
};