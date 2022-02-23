/* Problem Statement:
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) 
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(256) = O(1)