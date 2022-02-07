/*Problem-statement:
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int, bool> myMap;
        for (auto& num: nums) 
        {
            if (myMap.find(num) != myMap.end())
                return true;
            myMap.insert(make_pair(num, true));
        }
        return false;    
    }
};

//Time Complexity:  O(n)
//Space Complexity: O(n)