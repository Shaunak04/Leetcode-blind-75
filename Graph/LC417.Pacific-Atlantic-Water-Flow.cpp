/* Porblem Statement:
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic 
Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean
 touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer 
matrix heights where heights[r][c] represents the height above sea level of the cell 
at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells 
directly north, south, east, and west if the neighboring cell's height is less than 
or equal to the current cell's height. Water can flow from any cell adjacent to an 
ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that 
rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution 
{
public:
    int rows, cols;
	// denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool>> atlantic, pacific;
	vector<vector<int>> ans;  
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) 
    {
        if(!size(mat)) return ans;
        rows = size(mat), cols = size(mat[0]);
        atlantic = pacific = vector<vector<bool>> (rows, vector<bool>(cols, false));
		// perform dfs from all edge cells (ocean-connected cells)
        for(int i = 0; i < rows; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, cols - 1); // pacific from top, atlantic from bottom
        for(int i = 0; i < cols; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, rows - 1, i); // pacific from left, atlantic from right
        return ans;
    }
    
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j)
    {        
        if(visited[i][j]) return;
        visited[i][j] = true;
        
		// if cell reachable from both the oceans, insert into final answer vector
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
        
		// dfs from current cell only if height of next cell is greater
        if(i + 1 <  rows && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
        if(j + 1 <  cols && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
};

// Time Complexity:
// Space Complexity: 