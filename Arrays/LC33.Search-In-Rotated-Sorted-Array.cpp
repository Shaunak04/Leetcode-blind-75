/* Problem Statement:
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2]. Given the array nums after 
the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            
            else if(nums[mid]>=nums[start]) // correct sorted format as we expect
            {
                if(target>=nums[start] && target<=nums[mid]) // if the number lies in sorted start and mid
                {
                    end = mid -1;
                }
                else
                {
                    start = mid+1;// array is sorted without rotation and we search from mid to end
                }
            }
            else
            {
                if(target<=nums[end] && target>=nums[mid]) // if number lies between mid to end becuase of rotation
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return -1;
        
    }
};

// Time complexity: O(logN)
// Space Complexity: O(1)