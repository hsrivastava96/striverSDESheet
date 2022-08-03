class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> rs, cs;
        int cR = -1, cC = -1;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i != cR)
                    {
                        rs.push_back(i);
                        cR = i;
                    }
                    if(j != cC)
                    {
                        cs.push_back(j);
                        cC = j;
                    }
                }
            }
        }
        
        for(auto i:rs)
        {
            for(int j = 0; j < c; j++)
                matrix[i][j] = 0;
        }

        for(auto j:cs)
        {
            for(int i = 0; i < r; i++)
                matrix[i][j] = 0;
        }
    }
};