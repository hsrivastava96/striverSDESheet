class Solution {
public:
    
    int getBlkId(int r, int c)
    {
//         find blk id
        int blkId = 0;
        if(r >= 0 && r <= 2)
        {
            if(c >= 0 && c <= 2)
                blkId = 0;
            else if(c >= 3 && c <= 5)
                blkId = 1;
            else
                blkId = 2;
        }
        else if(r >= 3 && r <= 5)
        {
            if(c >= 0 && c <= 2)
                blkId = 3;
            else if(c >= 3 && c <= 5)
                blkId = 4;
            else
                blkId = 5;
        }
        else
        {
            if(c >= 0 && c <= 2)
                blkId = 6;
            else if(c >= 3 && c <= 5)
                blkId = 7;
            else
                blkId = 8;
        }
        return blkId;
    }
    
    bool isPossible(int r, int c, char val, vector<vector<char>> &board)
    {        
        int bSR = 3*(r/3), cSR = 3*(c/3), cCount = 0, rCount = 0, cS = 0, rS = 0;
        cS = cSR;//6
        rS = bSR;//3
        for(int i = 0; i < 9; i++)
        {
            if(board[r][i] == val)
                return false;
            if(board[i][c] == val)
                return false;
            if(board[rS][cS] == val)
                return false;
            if(cCount == 2)
            {
                cS = cSR;//6
                rS = bSR+1;//4
                cCount = 0;
            }
            else
            {
                cS++;//7, 8, 7, 8
                cCount++;//1, 2, 1, 2
            }
        }
        return true;
    }
    
    int sudokuSolver(vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1'; k <= '9'; k++)
                    {
                        if(isPossible(i, j, k, board))
                        {
                            board[i][j] = k;
                            int res = sudokuSolver(board);
                            if(res == 1)
                                return 1;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
        
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        sudokuSolver(board);
    }
};