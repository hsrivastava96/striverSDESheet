class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size(), i = 0, flag = 0, j =0, ind = 0;
        
        i = n-1;
        while(i > 0 && nums[i] <= nums[i-1])
            i--;
        
        if(i == 0)
            sort(nums.begin(), nums.end());
        else
        {
            sort(nums.begin()+i, nums.end());
            j = n-1;
            while(j > i-1 && nums[j] > nums[i-1])
                j--;
            if(j == n-1)
                ind = j;
            else
                ind = j+1;
            nums[i-1] = nums[ind] + nums[i-1];
            nums[ind] = nums[i-1] - nums[ind];
            nums[i-1] = nums[i-1] - nums[ind];
        }        
    }
};