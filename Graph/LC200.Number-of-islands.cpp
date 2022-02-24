/* Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's 
(water), return the number of islands. An island is surrounded by water and is formed 
by connecting adjacent lands horizontally or vertically. You may assume all four edges
 of the grid are all surrounded by water.
*/

class Solution {
public:
    void mark_island(vector<vector<char>>& grid, int i,int j, int row, int col)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]!='1')
        {
            return ;
        }
        grid[i][j] = '2';
        mark_island(grid,i+1,j,row,col);
        mark_island(grid,i,j+1,row,col);
        mark_island(grid,i-1,j,row,col);
        mark_island(grid,i,j-1,row,col);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        if(grid.size()==0)
        {
            return 0;
        }
        int col = grid[0].size();
        int i=0;
        int j=0;
        int num_island=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_island(grid,i,j,row,col);
                    num_island++;
                }
            }
        }
        
        return num_island;
    }
};

// Time Complexity: O(4^n)
// Space Complexity: O(1)