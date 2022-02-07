/* Problem Statement:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that 
the solution set must not contain duplicate triplets.
*/

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> triplets;
        if(nums.size() < 3)    
        {
            return triplets;
        }
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++)  
        {
            map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] > 0) break; // sum of three numbers cannot be 0, so break, no answer further
            if(i > 0 && nums[i] == nums[i-1])   continue; // skip duplicates
			
            for(int j = i+1; j < nums.size(); j++)
            {
                int target = -(nums[i]+nums[j]);
                if(map.find(target)!=map.end() && map[target]> j) // answer found with valid condition indices
                {
                    triplets.push_back({nums[i],nums[j],target});
                }
                j = map[nums[j]]; // update
            }
        }
        return triplets;
    }
};

// Time Complexity:  O(N*N)
// Space Complexity: O(1)