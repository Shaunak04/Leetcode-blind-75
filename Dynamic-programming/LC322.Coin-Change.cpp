/* Problem Statement:
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money. Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        int n = coins.size();
        int dp[n+1][amount+1];
         
        for(int i=0; i<=amount; i++)
        {
            dp[0][i] = INT_MAX-1;
        }
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][amount]==INT_MAX || dp[n][amount]==INT_MAX-1) ? -1 : dp[n][amount];
    }
}

// Time Complexity: O(n*amount)
// Space Complexity: O(n*amount)
