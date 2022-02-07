/*Problem Statement:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size()-1, left = 1, right = 1;
        vector<int> res(n+1, 1);
        for(int i=0; i<=n; i++) 
        {
            res[i] *= left;
            res[n-i] *= right;
            left *= nums[i];
            right *= nums[n-i];
        }
        return res;
    }
};

//Time complexity:  O(n)
//Space complexity: O(n), if answer array is ignored -> O(1)