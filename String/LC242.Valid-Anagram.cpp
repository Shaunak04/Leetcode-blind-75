/* Problem Statement:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different 
word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int> um;
        for(char i:s)
        {
            um[i]++;
        }
        for(char i:t)
        {
            um[i]--;
        }
        for(int i=0;i<um.size();i++)
        {
            if(um[i]!=0) return false;
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)