/* Problem Statement: 
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<set<int>> rows(9), cols(9), boxx(9);
        for(int i = 0; i < 9; i++) 
        {
            for(int j = 0; j < 9; j++) 
            {  
                if (board[i][j] == '.') continue;
                
                int pos = board[i][j] - '0';
                if (rows[i].count(pos) || cols[j].count(pos) || boxx[(i/3)*3 + j/3].count(pos)) return false;
                rows[i].insert(pos);
                cols[j].insert(pos);
                boxx[(i/3)*3 + j/3].insert(pos);
            }
        }
        return true;    
    }
};

// Time Complexity: O(9*9)
// Space Complexity: O(9)