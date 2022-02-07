/* Problem statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())//check for the already found index
            {
                ans = {i,m[target-nums[i]]};
                break;
            }
            m[nums[i]] = i;//else store the index of the number in map
        }
        return ans; 
    }
};

// Time complexity: O(n)
// Space complexity: O(n)