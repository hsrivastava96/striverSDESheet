
/*
    Algo:
    Now, at every node we are trying to find the minimum strength needed to reach the end node
    While doing that we are trying to remember the answer for all index
*/

#include<unordered_map>
#include<bits/stdc++.h>
int min(int a, int b)
{
    return (a < b)?a:b;
}

int getMin(int ind, int n, vector<int> &h, unordered_map<int, int> &dp)
{
    if(ind == n-1)
        return 0;
    if(dp.find(ind) != dp.end())
        return dp[ind];
    else
    {
        int left = INT_MAX, right = INT_MAX;
        left = abs(h[ind] - h[ind + 1]) + getMin(ind + 1, n, h, dp);
        if(ind + 2 < n)
            right = abs(h[ind] - h[ind+2]) + getMin(ind + 2, n, h, dp);
        dp[ind] = min(left, right);
        return dp[ind];
    }
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    unordered_map<int, int> dp;
    return getMin(0, n, heights, dp);
}