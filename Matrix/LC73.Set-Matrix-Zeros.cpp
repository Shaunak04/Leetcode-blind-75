/* Problem Statement:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.
*/

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        if(rows<=0) return ;
        int cols = matrix[0].size();
        cout<<rows<<" "<<cols;
        bool FirstRow = false;
        bool FirstCol = false;

        for(int i=0 ; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) FirstRow = true;
                    if(j==0) FirstCol = true;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<rows; i++)
        {
            for(int j=1; j<cols; j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(FirstRow)
        {
            for(int i=0 ;i<cols;i++)
            {
                matrix[0][i] = 0;
            }
        }

        if(FirstCol)
        {
            for(int i=0;i<rows;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// Time complexity: O(m*n)
// Space complexity: O(1)