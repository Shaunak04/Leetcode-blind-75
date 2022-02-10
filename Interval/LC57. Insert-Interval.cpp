/* Problem-statement:
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;
        int index = 0;
        while(index < intervals.size() && intervals[index][1]<newInterval[0])
        {
            result.push_back(intervals[index]);
            index++;
        }
        while(index<intervals.size() && intervals[index][0]<=newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        result.push_back(newInterval);
        while(index<intervals.size())
        {
            result.push_back(intervals[index]);
            index++;
        }
        return result;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n), considering the result vector