/*
    Algo:

    For top down DP:
    1. We can move either down or diagonally
    for both the cases base condition is if we reach any of the last row's cell
    i.e. if(i == n-1)
    2. All possible paths: diagonal and down
    3. Minimum: min(diag, down)

    We memoise for each index so that if the same subproblem overlaps in any other case
    then we can directly return it's corresponding solution

    For bottom up approach (Tabulation):
    
    Fill all the bottom row for dp matrix from triangle matrix
    Now, move from right to left and bottom to up and keep finding min(diag, down) 
    and update the dp matrix
    ultimately dp[0][0] will hold our answer
    because by doing this, we are findning minimum for each cell to reach the bottom row 

*/

class Solution {
public:
    int min(int a, int b)
    {
        return (a<b)?a:b;
    }
    int getMin(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(i == n-1)
            return triangle[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        else
        {
            int diag = triangle[i][j] + getMin(i+1, j+1, n, triangle, dp);
            int down = triangle[i][j] + getMin(i+1, j, n, triangle, dp);
            
            return dp[i][j] = min(diag, down);
        }
    }
    
    int getMinTabulation(int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        for(int i = n-1; i >=0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                if(i == n-1)
                    dp[i][j] = triangle[i][j];
                else
                {
                    int diag = triangle[i][j] + dp[i+1][j+1];
                    int down = triangle[i][j] + dp[i+1][j];
                    
                    dp[i][j] = min(diag, down);
                }
            }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return getMin(0, 0, n, triangle, dp);
        return getMinTabulation(n, triangle, dp);
    }
};