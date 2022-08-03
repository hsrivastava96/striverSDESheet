class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<int> v1, v2;
        v1.push_back(1);
        v2.push_back(1);
        v2.push_back(1);
        
        vector<vector<int>> res;
        res.push_back(v1);
        if(numRows == 1)
            return res;
        res.push_back(v2);
        if(numRows == 2)
            return res;
        for(int i = 2; i < numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 0; j < res[i-1].size() - 1; j++)
                temp.push_back(res[i-1][j]+res[i-1][j+1]);                
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};