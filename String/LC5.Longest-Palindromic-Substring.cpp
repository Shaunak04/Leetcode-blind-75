/* Problem Statement:
Given a string s, return the longest palindromic substring in s.
*/

class Solution 
{
public:

    void extendPalindrom(string s, int l, int r, int &start, int &len)
    {
        while(l>=0 && r<s.length() && s[l]==s[r]) // check for palindrome with 2 pointers
        {
            l--;
            r++;
        }
        if(len < r-l-1) // longer palindrome found
        {
            start = l+1;
            len = r-l-1;
        }
    }
    
    string longestPalindrome(string s) 
    {
        int n = s.length();
        int start = 0;
        int len = 1;
        if(n<2)
        {
            return s;
        }
        for(int i=0; i<n-1; i++)
        {
            extendPalindrom(s,i,i,start, len);
            extendPalindrom(s,i,i+1,start, len);
        }
        return s.substr(start, len);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)