/* Problem Statement:
Given an array of distinct integers nums and a target integer target, return the number of 
possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.

*/
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int dp[n+1][target+1];
        
        for(int i=0; i<=target; i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=target; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};

// Time Complexity: O(n*target)
// Space Complexity: o(n*target) 