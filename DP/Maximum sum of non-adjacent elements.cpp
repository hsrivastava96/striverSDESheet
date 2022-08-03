/*
    Algo:
    Apply the same logic of select and not select
    Here, if we are selecting then we need to check if ind + 2 is possible or not
    if possible then we call ind + 2 function's max sum from that node to end
    otherwise we consider current node as max value in selection scenario

    for not selection scenario we simple move to the next node
*/

#include<bits/stdc++.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}
int getMaxSum(int ind, int n, vector<int> &nums, unordered_map<int, int> &dp)
{
    if(ind == n-1)
        return nums[n-1];
    if(dp.find(ind) != dp.end())
        return dp[ind];
    else
    {
//         select
        int left = 0;
        if(ind+2 < n)
            left = nums[ind] + getMaxSum(ind+2, n, nums, dp);
        else
            left = nums[ind];
// not select
        int right = getMaxSum(ind+1, n, nums, dp);
        
        dp[ind] = max(left, right);
        return dp[ind];
    }
}

int maximumNonAdjacentSum(vector<int> &nums)
{
        // Write your code here.
    int n = nums.size();
    unordered_map<int, int> dp;
    return getMaxSum(0, n, nums, dp);
}