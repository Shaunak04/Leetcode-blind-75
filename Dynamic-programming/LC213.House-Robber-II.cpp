/* Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed. All houses at this place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int robOriginal(vector<int>& nums, int start, int end) 
    {
        int a = 0, b = 0, res = 0;
        
        for(int i = start; i < end; ++i){
            res = max(b + nums[i], a);
            b = a;
            a = res;
        }
        return res;
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        return max(robOriginal(nums, 0, n-1), robOriginal(nums, 1 , n));
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)