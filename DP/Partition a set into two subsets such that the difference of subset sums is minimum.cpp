
/*
    Algo:
    Here, consider that target is totalSum

    Now, use tabulation method to find out all possible combinations
    At the end you will have all possible targets in 0th row

    Now, for all possible target find subset2 sum = totalSum - collumn index of dp[0][collumn index]
    After getting sum1 and sum2 get abs(sum1 - sum2) 
    now check if abs difference is less than minimum
    if yes then update minimum

    return minimum
*/


int min(int a, int b)
{
    return (a<b)?a:b;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int totalSum = 0;
    for(auto it:arr)
        totalSum+=it;
    int k = totalSum;
    vector<vector<int>> dp(n, vector<int>(totalSum+1, false));
    
    vector<vector<bool>> dpT(n, vector<bool>(k+1, false));
    
    for(int i = 0; i < n; i++)
        dpT[i][0] = true;
    if(arr[n-1] <= k)
        dpT[n-1][arr[n-1]] = true;
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = k; j >= 1; j--)
        {
           bool notTaken = dpT[i+1][j];
           bool taken = false;
           if(arr[i] <= j)
               taken = dpT[i+1][j - arr[i]];
            
           dpT[i][j] = taken || notTaken;
        }
    }
    
    int mini = 1e9;
    for(int i = 0; i <= totalSum; i++)
    {
        if(dpT[0][i])
            mini = min(mini, abs(totalSum - 2*i));
    }
    return mini;
}
