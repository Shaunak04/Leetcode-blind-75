/* Problem Statement:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated 
sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution 
{
public:
    bool helper(string &s, vector<string>& wordDict, int n, unordered_map<string, bool> &dp) 
    {
		// if item list is empty
        if(n == 0) return false;
		
		// if string s is empty
        if(s.size()==0) return true;
        
		string currDictWord = wordDict[n-1];
        int currSize = currDictWord.size();
        
		// if the current item maches the input string
        if(currDictWord == s) return true;
		
		// if we have already computed this result
        if(dp.find(s) != dp.end())
            return dp[s];
			
        // 2 possibilities : Prefix, not Prefix :
        string prefix = s.substr(0, currSize);
        
        if(currDictWord == prefix) 
        {
			// either we pick this item and reduce the string s by removing the prefix, OR we do not pick this item and move to the next item
            string rest = s.substr(currSize);
            return dp[s] = helper(rest, wordDict, wordDict.size(), dp) || helper(s, wordDict, n-1, dp);
        } 
        else 
        {
			// not pick this item and move to the next word
            return dp[s] = helper(s, wordDict, n-1, dp);
        }
    }
    
    
    bool wordBreak(string &s, vector<string>& wordDict) 
    {
        unordered_map<string, bool> dp;
        return helper(s, wordDict, wordDict.size(), dp);
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n)