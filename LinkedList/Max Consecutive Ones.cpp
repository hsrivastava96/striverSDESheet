class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max = -1, tempFreq = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(tempFreq > max)
                    max = tempFreq;
                tempFreq = 0;
            }
            else
                tempFreq++;
        }
        if(tempFreq > 0)
        {
            if(tempFreq > max)
                max = tempFreq;
        }
        return max;
    }
};