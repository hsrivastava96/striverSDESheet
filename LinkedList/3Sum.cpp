class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size(), prevSelected = 0;
        vector<vector<int>> ans;
        
       sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            int sum = 0, l = i+1, r = n-1;
            while(l<r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    vector<int> ds;
                    ds.push_back(nums[i]);
                    ds.push_back(nums[l]);
                    ds.push_back(nums[r]);
                    ans.push_back(ds);
                    
                    while(l<r && nums[l] == ds[1])
                        l++;
                    while(l<r && nums[r] == ds[2])
                        r--;
                }
                else if(sum > 0)
                    r--;
                else
                    l++;
            }
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};