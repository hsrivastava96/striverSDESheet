/*
    Algo:
    Same as sum of non adjacent subsequence max sum
    Here, we use two arrays to solve our problem
    Array1 : will not include last element
    Array2 : will not include first element
    to avoid the inclusion of both case
    then we find the max of both the scenarios and that will be our answer

*/

#include<bits/stdc++.h>

long long int max(long long int a, long long int b)
{
    return (a>b)?a:b;
}
long long int getMaxSum(long long int ind, long long int n, vector<int> &nums, unordered_map<long long int, long long int> &dp)
{
    if(ind == n-1)
        return nums[n-1];
    if(dp.find(ind) != dp.end())
        return dp[ind];
    else
    {
//         select
        long long int left = 0;
        if(ind+2 < n)
            left = nums[ind] + getMaxSum(ind+2, n, nums, dp);
        else
            left = nums[ind];
// not select
        long long int right = getMaxSum(ind+1, n, nums, dp);
        
        dp[ind] = max(left, right);
        return dp[ind];
    }
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    long long int n = valueInHouse.size();
    unordered_map<long long int, long long int> dp1, dp2;
    long long int max1 = 0, max2 = 0;
    vector<int> ds1, ds2;
    
    if(n == 1)
        return valueInHouse[0];
    for(int i = 0; i < valueInHouse.size()-1; i++)
        ds1.push_back(valueInHouse[i]);
    for(int i = 1; i < valueInHouse.size(); i++)
        ds2.push_back(valueInHouse[i]);
        
    max1 = getMaxSum(0, n-1, ds1, dp1);
    max2 = getMaxSum(0, n-1, ds2, dp2);
    return max(max1, max2);
}