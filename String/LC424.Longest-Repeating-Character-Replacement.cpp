/* Problem Statement:
You are given a string s and an integer k. You can choose any character of the string and change 
it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing 
the above operations.
*/

class Solution 
{
public:
    
    int getFreq(int arr[])
    {
        int max=0;
        for(int i=0; i<26; i++)
        {
            if(arr[i]>max)
            {
                max = arr[i];
            }
        }
        return max;
    }
    
    int characterReplacement(string s, int k) 
    {
        int arr[26];
        memset(arr, 0, sizeof arr);
        int maxLen = 0;
        int left = 0;
        int n = s.length();
        for(int right=0; right<n; right++)
        {
            arr[s[right]-'A']++;
            
            if(right-left+1 - getFreq(arr) > k)
            {
                arr[s[left]-'A']--;
                left++;
            }
            
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};

// Time Complexity: O(n*26)
// Space Complexity: O(1)