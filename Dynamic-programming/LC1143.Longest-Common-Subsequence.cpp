/* 
Problem statement: Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0. A subsequence of a string is a new string generated from the original 
string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
class Solution 
{
public:
    int longestCommonSubsequence(string a, string b) 
    {
        int n = a.length();
        int m = b.length();
        int i=0, j=0;
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        for(i=1 ;i<n+1; i++)
        {
            for(j=1; j<m+1; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
// Time Complexity: O(a*b)
// Space Complexity: O(a*b)