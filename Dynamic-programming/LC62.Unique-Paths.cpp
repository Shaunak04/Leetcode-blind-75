/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the 
bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n) return 0; // out of bounds
        if(i==m-1 && j==n-1) return 1; // reach end
        if(dp[i][j]!=-1) // already calculated, so return memoized value
        {
            return dp[i][j];
        }
        return dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp); // bottom call + right call
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)