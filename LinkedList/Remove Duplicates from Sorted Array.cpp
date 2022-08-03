class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> ds;
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else
        {
            ds.push_back(nums[0]);
            int currDsInd = 0;
            for(int i = 1; i < n; i++)
            {
                if(nums[i] != ds[currDsInd])
                {
                    ds.push_back(nums[i]);
                    currDsInd++;
                }
            }
            int i = 0, sz = ds.size();
            
            while(i < sz)
            {
                nums[i] = ds[i];
                i++;
            }
            return currDsInd+1;
        }
    }
};