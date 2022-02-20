/* Problem Statement:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int lastGoodIdx = nums.size()-1;
        for(int i = nums.size()-1; i>=0; i--)
        {
            if(i + nums[i] >= lastGoodIdx)
            {
                lastGoodIdx = i;
            }
        }
        return lastGoodIdx == 0;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)