// Valid Sudoku

// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.



//My solution

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        if(board.size() != 9 || board[0].size() != 9)
            return false;
        
        for(int i = 0; i< 9 ; i++)
        {
            if(checkNine(board,i,i,0,8) == false)
                return false;
            if(checkNine(board,0,8,i,i) == false)
                return false;
        }
        
        for (int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if (!checkNine(board,i*3,i*3+2,j*3,j*3+2)) return false;
            }
            
        return true;
    }
    
    bool checkNine(vector<vector<char>>& board,int x1,int x2,int y1,int y2)
    {
        vector<int> countArray(board.size(),0);
        
        for(int i = x1;i<=x2;i++)
            for(int j = y1;j<=y2;j++)
            {
                if(board[i][j] != '.')
                {
                    int k = board[i][j] - '1';
                    if(countArray[k] == 0)
                    {
                        countArray[k] = 1;
                    }
                    else
                        return false;
                }
            }
        
        return true;
    }
};