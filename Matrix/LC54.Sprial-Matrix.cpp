/* Problem Statement:
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> result;
        int up = 0;
        int down = r-1;
        int left = 0;
        int right = c-1;
        
        while(result.size() < r*c)
        {
            for(int i=left;i<=right && result.size()<r*c; i++) // [left, right]
            {
                result.push_back(matrix[up][i]);
            }
            for(int i=up+1;i<=down-1 && result.size()<r*c; i++)// [up+1, down-1]
            {
                result.push_back(matrix[i][right]);
            }
            for(int i=right;i>=left && result.size()<r*c; i--)// [right, left]
            {
                result.push_back(matrix[down][i]);
            }
            for(int i=down-1;i>=up+1 && result.size()<r*c; i--)// [down-1, up+1]
            {
                result.push_back(matrix[i][left]);
            }
            // move inwards
            left++;
            right--;
            up++;
            down--;
        }
        return result;
    }
};

// Time complexity: O(m*n)
// Space COmplexity: O(m*n), if you consider the result vector