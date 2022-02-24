/* Problem Statement:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(auto i:nums)
        {
            mp[i] = 1;
        }
        int maxAns = 0;
        for(int i:nums)
        {
            if(mp.find(i-1)==mp.end())
            {
                int tempAns = 1;
                while(mp.find(i+1)!=mp.end())
                {
                    tempAns++;
                    i++;
                }
                maxAns = max(tempAns, maxAns);
            }
        }
        return maxAns;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)