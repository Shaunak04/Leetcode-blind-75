/* Problem Statement:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0; i<(n+1)/2; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                int temp = matrix[n-1-j][i]; // temp <- bottom left
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; // bottom left <-  bottom right
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; // bottom right <- top right
                matrix[j][n-1-i] = matrix[i][j]; // top right <- top left
                matrix[i][j] = temp; // top left <- temp
            }
        }
    }
};

// Time Complexity: O(n*n)
// Space Complexity: O(1)