/* Problem Statement:
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s 
such that every character in t (including duplicates) is included in the window. If there is no such 
substring, return the empty string "". The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.
*/

class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        if(s.length() < t.length()) return "";
        int m = s.length();
        int n = t.length();
        unordered_map<char, int> mp;
        for(char &c:t)
        {
            mp[c]++;
        }
        int left=0, right=0, minLen = INT_MAX, minStart = 0;
        int rem = n;
        while(right<m)
        {
            // find the first valid substring
            if(--mp[s[right]]>=0)
            {
                rem--;
            }
            right++;
            // try to reduce the window size while all chars exist
            while(rem==0)
            {
                if(right-left < minLen)
                {
                    minStart = left;
                    minLen = right-left;
                }
                if(++mp[s[left]]>0) rem++;
                left++;
            }
        }
        return minLen < INT_MAX ? s.substr(minStart, minLen): "";
    }
};

// Time Complexity: 
// Space Complexity: 