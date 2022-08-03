/*
    Algo:

    Now, apply the same approach to traverse through all possible paths

    With one slight change, to get the summation of all the paths, instead of sending 1
    after reaching to m-1, n-1 node send it's value

    so, for each i, j we shall get the sum from that index to bottom right

    Now, since we want to get the minimum of these paths,
    take the minimum and memoise it
    and return the memoised value
*/

class Solution {
public:
    int min(int a, int b)
    {
        return (a<b)?a:b;
    }
    
    int pathSum(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i == m-1 && j == n-1)
            return grid[i][j];
        if(i >= m || j >= n)
            return 1e9;
        if(dp[i][j] != -1)
            return dp[i][j];

        int right = pathSum(i, j+1, m, n, grid, dp);
        int down = pathSum(i+1, j, m, n, grid, dp);
        
        dp[i][j] = min(grid[i][j] + right, grid[i][j] +  down);
        return dp[i][j];
    }
    int tabulation(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                    dp[i][j] = grid[i][j];
                else
                {
                    int right = grid[i][j], down = grid[i][j];
                    if(i < m-1)
                        down+=dp[i+1][j];
                    else
                        down+=1e9;
                    if(j < n-1)
                        right+=dp[i][j+1];
                    else
                        right+=1e9;
                    dp[i][j] = min(down, right);
                }
            }
        }
        return dp[0][0];
    }

    int minSumPath(vector<vector<int>> &grid) {
        // Write your code here.
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));

    //         return pathSum(0, 0, m, n, grid, dp);
            // return tabulation(m, n, grid, dp);
    }
};