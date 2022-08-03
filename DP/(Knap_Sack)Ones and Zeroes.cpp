/*
    Algo:
    
    First prepare a 2D Matrix to store Ones and Zeroes count for each string

    Memoization:

    Check if we have reached last index:
        - In this case if lcurrent available weight in our sack is >= wt of last index object
        (Here, if # of 0s and # of 1s is <= m and n respectively)
        then we say that this string can be included so we return 1
        - Otherwise we return 0         

    Check if there is no space left (0s == 0 and 1s == 0)
        - If yes then return 0

    Now, we have two cases for a given object 
        - Select if it's m and n are within threshold or <= available spots of 0s and 1s
            -In this case since we are selecting add 1 to the recursive function call 
            and update 0s and 1s left after selecting this string
        - Do not select current string
            - In this case simply ove to the next string w/o updating available 0s and 1s spots

        - Update our 3D DP with max of above two states
        - Return answer
    
    Tabulation:

    Here,
    Simply put 1 to all combinations of 0s and 1s >= last string's 1s and 0s to max possible value for 0s and 1s
    
    Then update our 3D DP for the next boundary condition of 0 0s and 0 1s
        - Set everything for this case to 0

    Then iteratively traverse through the strings
    Keep calculation for each index combination in our 3D DP 

    Athe the end return first string's m, n value as answer     


*/

class Solution {
public:
    
    void updateZnO(vector<vector<int>> &ds, vector<string>& strs, int n)
    {
        for(int i = 0; i < n; i++)
        {
            int m = strs[i].length(), zC = 0, oC = 0;
            for(int j = 0; j < m; j++)
            {
                if(strs[i][j] == '0')
                    zC++;
                else
                    oC++;
            }
            ds[i][0] = zC;
            ds[i][1] = oC;
        }
    }
    
    int max(int a, int b)
    {
        return (a>b)?a:b;
    }
    
    int knapSack(int ind, int m, int n, int size, vector<vector<int>> &ds, vector<vector<vector<int>>> &dp)
    {
        if(ind == size - 1)
        {
            if(ds[ind][0] <= m && ds[ind][1] <= n)
                return 1;
            return 0;
        }
        if(m == 0 && n == 0)
            return 0;
        if(dp[ind][m][n] != -1)
            return dp[ind][m][n];
        
        // Pick
        int pick = 0;
        if(ds[ind][0] <= m && ds[ind][1] <= n)
            pick = 1 + knapSack(ind+1, m-ds[ind][0], n - ds[ind][1], size, ds, dp);
        
        // Not Pick
        int nPick = knapSack(ind+1, m, n, size, ds, dp);
        
        return dp[ind][m][n] = max(pick, nPick);
    }
    
    int tabulation(int m, int n, int size, vector<vector<int>> &ds, vector<vector<vector<int>>> &dp)
    {
        // Set base conditions true scenarios
        
        // For all last indexes less than or equal to m and n
        for(int i = ds[size-1][0]; i <= m ; i++)
        {
            for(int j = ds[size-1][1]; j <= n ; j++)
                dp[size-1][i][j] = 1;
        }
        
        // For all m == 0 and n == 0
        for(int i = 0; i < size; i++)
            dp[i][0][0] = 0;
        
        for(int i = size-2; i >= 0; i--)
        {
            for(int j = m; j >= 0; j--)
            {
                for(int k = n; k >= 0; k--)
                {
                    int nPick = dp[i+1][j][k];
                    int pick = 0;
                    if(ds[i][0] <= j && ds[i][1] <= k)
                        pick = dp[i+1][j - ds[i][0]][k - ds[i][1]] + 1;
                    
                    dp[i][j][k] = max(pick, nPick);
                }
            }
        }
        
        return dp[0][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int size = strs.size();
        vector<vector<int>> ds(size, vector<int>(2, 0));
        // vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        updateZnO(ds, strs, size);
        
        
        // return knapSack(0, m, n, size, ds, dp);
        return tabulation(m, n, size, ds, dp);
    }
};