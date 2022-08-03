
/*
    Algo:

    Here, apply the same concept of checking if a target sum exist or not 
    If it does, instead of returning true, return 1 otherwise 0
    In case our target == 0 and our last index is also 0 then return 2 
    because here we have two ways (Select last or Not select last)

    otherwise 
    check total count take current index
    or if we do not take current index in our subset

    return the sum of both


*/ 

int countSub(int ind, int n, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if(ind == n-1)
    {
        if(nums[n-1] == target && target == 0)
            return 2;
        else if(nums[n-1] == target || target == 0)
            return 1;
        return 0;
    }
    // if(target == 0)
    //     return 1;
    if(target < 0)
        return 0;
    if(dp[ind][target] != -1)
        return dp[ind][target];
    
    int take = countSub(ind+1, n, target - nums[ind], nums, dp);
    int notTake = countSub(ind+1, n, target, nums, dp);
    
    return dp[ind][target] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return countSub(0, n, tar, num, dp);
}