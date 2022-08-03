/*
    Intuition:

    In this problem we are trying to find out if two portions of a given array have same sum.
    This indirectly means that two subsets of a given array have sum = totalSum/2

    Thus, we solve this problem by checking if the total sum is even or odd first 
    For odd -> Not possible
    For even -> Possible if we have a subSet of sum = totalSum/2
    
    Algo:
    
    Step 1: Calculate total sum
    Step 2: Check if Sum is even (Move to step 3 or else step 12)
    Step 3: Calculate totalSum/2 (This becomes our target to check if a subSet exist with target sum)
    Step 4: Start from 0th index and check if our index is valid)
    Step 5: Check for boundary condition of last index (For last index, possible if current target = arr[n-1])
    Step 6: Check for boundary condition if target == 0 then return true
    Step 7: Check if target is negative (This means that last index value was greater than target. So, return false)
    Step 8: Check if for current index and current target we already have calculated the result
    If yes then return the output 
    Step 9: If none of the boundary conditions are true
    then check if by taking or not taking we get a subSet witht he target sum
    Step 10: return or of taken and not taken
    Step 11: return output of subSet function
    Step 12: return false because total sum is odd 
*/

class Solution {
public:
    
    bool subSet(int ind, int n, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind == n-1)
            return (nums[n-1] == target);
        if(target == 0)
            return true;
        if(target < 0)
            return false;
        if(dp[ind][target] != -1)
            return (dp[ind][target] == 1);
        
        bool take = subSet(ind+1, n, target-nums[ind], nums, dp);
        bool notTake = subSet(ind+1, n, target, nums, dp);
        
        return dp[ind][target] = (take || notTake)?1:0;
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size(), totalSum = 0;
        for(auto it:nums)
            totalSum+=it;
        
        if(totalSum % 2 == 0)
        {
            int target = totalSum/2;
            vector<vector<int>> dp(n, vector<int>(target+1, -1));
            return subSet(0, n, target, nums, dp);
        }
        return false;
    }
};