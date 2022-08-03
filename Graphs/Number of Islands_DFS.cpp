/*
    Algo:
    Traverse via DFS, keep visiting all valid 1s and in recursive call
    call for all the adjacent neighbors of current cell except the diagonal ones
    because the diagonal ones will anyways be accessed in the adjacent cells of current cell

    Every time there is an 1, increment counter because it will either be belonging to a cluster of land or 
    it will be a single land (island)
*/

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid)
    {
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] != '1')
            return;
        
//         visit current index having 1 and set it as 2 and check all it's adjacent nodes which // are also 1
        grid[i][j] = 2;

        dfs(i+1, j, n, m, grid);
        dfs(i-1, j, n, m, grid);
        dfs(i, j+1, n, m, grid);
        dfs(i, j-1, n, m, grid);
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), count = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j, n, m, grid);
                    count++;
                }
            }
        }
        return count;
    }
};