
int max(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}

int getMax(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if(i >= m || j >= n || j < 0)
        return -1e9;
    if(i == m - 1)
        return matrix[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int rDiag = matrix[i][j] + getMax(i+1, j+1, m, n, matrix, dp);
    int lDiag = matrix[i][j] + getMax(i+1, j-1, m, n, matrix, dp);
    int down = matrix[i][j] + getMax(i+1, j, m, n, matrix, dp);
    
    return dp[i][j] = max(rDiag, lDiag, down);
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size(), n = matrix[0].size(), max = -1e9;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
    {
        int val = getMax(0, i, m, n, matrix, dp);
        if(max < val)
            max = val;
    }
    return max;
}