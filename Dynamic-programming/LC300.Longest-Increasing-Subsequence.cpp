/* Problem Statement:
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence 
of the array [0,3,1,6,2,2,7].
*/

class Solution 
{
public:
    // strictly increasing means duplicates need to be skipped in answer
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int len = 0;
        for(auto curr:nums)
        {
            if(len==0 || nums[len-1]<curr) // if subsequence is empty (len=0) or the last element looked in subsequence is less than current element, consider the current element in the Longest Increasing Subsequence
            {
                nums[len++] = curr;
            }
            else
            {
                *lower_bound(begin(nums), begin(nums)+len, curr) = curr;
            }
        }
        return len;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity:  O(1)