/* Problem Statement:
Given an integer n, return an array ans of length n + 1 such that 
for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/

class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans(n+1);
        int offset = 1;
        for(int i=1; i<n+1; ++i)
        {
            if(offset*2==i)
            {
                offset*=2;
            }
            ans[i] = ans[i-offset] + 1;
        }
        return ans; 
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)