class Solution {
public:
    bool isPossible(int row, int col, vector<string> &board, int n)
    {
        int rowCopy = row, colCopy = col;
        
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        row = rowCopy;
        col = colCopy;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        
        col = colCopy;
        while(col >= 0 && row < n)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }
        
        return true;
    }
    
    void solveNQ(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isPossible(row, col, board, n))
            {
                board[row][col] = 'Q';
                solveNQ(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board;
        vector<vector<string>> ans;
        
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board.push_back(s);
        
        solveNQ(0, board, ans, n);
        
        return ans;
    }
};