/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

class Solution 
{
public:
    int numDecodings(string s) 
    {
        int n = s.length();
        int last = 1;
        int ans = 1;
        int last_last = 1;
        if(s[0]=='0') return 0;
        if(n==1) return 1;
        for(int i=1; i<n; i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]>'2' || s[i-1]=='0') return 0;
                else ans = last_last;
            }
            else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7'))
            {
                ans = last + last_last;
            }
            else{
                ans = last;
            }
            last_last = last;
            last = ans;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)