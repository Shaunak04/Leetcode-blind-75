/* Problem Statement:
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
*/

class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int ans = n;
        for(int i=1, l=0, r=2; i<n; i++, l = i-1, r = i + 1)
        {
            while(l>=0 && r<n && s[l]==s[r]) l--, r++, ans++;
        }

        for(int i=1, l=0, r=1; i<n; i++, l=i-1, r = i)
        {
            while(l>=0 && r<n && s[l]==s[r]) l--, r++, ans++;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1s)