/*
    Algo:

    Memoisation:
    Check whether current target is present within any subset of current to end index
    
    We first check if target == 0
    then return true

    Otherwise we check if we have reached the last node
    Here, we check if last node is equal to the required target or not
    if Yes, return true else false

    Otherwise we check if we already have a solution for current index and target value
    if we do then we return that solution
    
    we check if target is negative, in that case we return false

    Otherwise 
    We check by including current value and exclude current value
    we memoise it by storing take || notTake in our dp array

    and return that or


    Tabulation:

    Set dpT matrix to all false
    Set for each row if k = 0 true dpT[0:n][0] = True
    Now, if for last index if we have target as it's own value then for that case we will have true as answer
    so, set that to true, if arr[n-1] <= k because if it is > k then it's substraction from k will lead us to 
    -ve value which gives false answer

    Now, traverse the matrix from 2nd last row and in reverse fashion and keep checking
    take and not take's or to get answer for current index and target combination
*/

bool subSet(int ind, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if(k == 0)
        return true;
    if(ind == n-1)
        return (arr[ind] == k);
    if(dp[ind][k] != -1)
        return (dp[ind][k] == 1);
    if(k < 0)
        return false;
    
    bool take = subSet(ind + 1, n, k - arr[ind], arr, dp);
    bool notTake = subSet(ind + 1, n, k, arr, dp);
    
    return dp[ind][k] = (take || notTake)?1:0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    
//     return subSet(0, n, k, arr, dp);
//    Tabulation
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
    return dpT[0][k];
}







