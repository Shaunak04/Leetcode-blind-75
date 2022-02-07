/* Problem Statement:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints 
of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such 
that the container contains the most water. Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        
        int max_water=0;
        while(left < right)
        {
            int l1 = height[left];
            int l2 = height[right];
            int final_height = min(l1,l2);
            int sum = final_height*(right-left);
            max_water = max(sum, max_water);
            if(l1>=l2)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return max_water;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)