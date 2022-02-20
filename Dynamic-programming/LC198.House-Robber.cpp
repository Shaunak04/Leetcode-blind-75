/* Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police if two adjacent houses were broken 
into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of
money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0) return 0;
        int a = 0;
        int b = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++)
        {
            res = max(a, b+nums[i]);
            b = a;
            a = res;
        }
        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)