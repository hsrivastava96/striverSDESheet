class Solution {
public:
    void comSum(int ind, int n, int sum, int target, vector<int> arr, vector<int> ds, vector<vector<int>> &ans)
    {
        if(sum == target)
            ans.push_back(ds);
        else if(ind == n)
            return;
        else if(sum > target)
            return;
        else
        {
            sum+=arr[ind];
            ds.push_back(arr[ind]);
            comSum(ind, n, sum, target, arr, ds, ans);
            
            sum-=arr[ind];
            ds.pop_back();
            comSum(ind+1, n, sum, target, arr, ds, ans);            
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        comSum(0, n, 0, target, candidates, ds, ans);
        return ans;
    }
};