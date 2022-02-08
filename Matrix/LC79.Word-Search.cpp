/* Problem Statement:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once
*/

class Solution 
{
public:
    
    bool dfs(int rows, int cols, int i, int j, vector<vector<char>>& board, string word, int curr)
    {
        if(curr==word.size()) return true; // found the whole word
        
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]!=word[curr]) return false; // out of bounds index or not matching character
        
        char c = board[i][j]; // store the current character in var c
        board[i][j] = '*'; // change the current index in board to '*'
        // recursively check all 4 directions
        bool ret = dfs(rows, cols, i-1, j, board, word, curr+1) || dfs(rows, cols, i+1, j, board, word, curr+1) || dfs(rows, cols, i, j-1, board, word, curr+1) || dfs(rows, cols, i, j+1, board, word, curr+1);
        board[i][j] = c; // re-assign the current index as c and continue dfs
        return ret;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(dfs(rows, cols, i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};

// Time Complexity:  O(m*n*4^k), ,m*n is size of board and k is length of input word, we search all 4 directions each time so 4^k
// Space Complexity: O(1), ignoring recursion stack space