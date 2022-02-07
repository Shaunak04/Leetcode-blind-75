/* Problem Statement:
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        int maxPos = ans;
        int maxNeg = ans;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                swap(maxPos, maxNeg);
            }
            maxPos = max(nums[i],maxPos*nums[i]);
            maxNeg = min(nums[i],maxNeg*nums[i]);
            ans = max(ans, maxPos);
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)