/* Problem-statement:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto interval : intervals) 
        {
            if(merged.empty() || merged.back()[1] < interval[0]) 
            {
                merged.push_back(interval);
            }
            else 
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n), considering the result vector