/*
    Algo:
    Initialise a DP Matrix of n*4 size
    column = 4 because initially we are sending the previous accessed index as 3
    and for that previous dp[ind][prev] will always be -1
    so, we would never get that as an answer

    Now, we check if we have a valid dp[ind][prev]
    if yes, we send our answer

    otherwise
    we check if we have reached the end node
    in that case we return the maximum of that node

    otherwise for current node we find the maximum by calculating max of all possible options
*/


int max(int a, int b)
{
    return (a > b)?a:b;
}

int maxSum(int ind, int prev, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    int n = points.size();
    if(dp[ind][prev] != -1)
        return dp[ind][prev];
    if(ind == n - 1)
    {
        int maxi = 0;
        for(int i = 0; i < 3; i++)
        {
            if(i != prev)
                maxi = max(maxi, points[n-1][i]);
        }
        return maxi;
    }
    
    int maxi = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i != prev)
        {
            int sum = points[ind][i] + maxSum(ind+1, i, points, dp);
            maxi = max(maxi, sum);
        }
    }
    dp[ind][prev] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return maxSum(0, 3, points, dp);
}