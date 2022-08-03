/*
    Algo:
    Step 1: Express in terms of (i, j) and find base case
    So, here we are expressing everything in terms of row and column
    Base case: either we will reach the destination else we will get out of the matrix
    
    Step 2: Do all possible stuffs/express all possible paths
    From one node to reach bottom right we can either move right or down
    so we move in both the directions and check if we can reach from that direction or not

    Step 3: at each node we get the unique paths to bottom right
    so we take the sum of right and down and put it into our dp 

    at the end we return our final sum 

*/

#include <bits/stdc++.h> 
int pathCount(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if((i == m - 1) && (j == n - 1))
        return 1;
    if(i > m-1 || j > n-1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int right = pathCount(i, j+1, m, n, dp);
    int down = pathCount(i+1, j, m, n, dp);
    
    return dp[i][j] = (right + down);
}
int uniquePaths(int m, int n) 
{
	// Write your code here.
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return pathCount(0, 0, m, n, dp);
}