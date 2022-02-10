/* Problem Statement:
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>> pq;
        int i=0;
        map<int, int> mp;
        for(int &n:nums)
        {
            mp[n]++;
        }
        for(auto &pair: mp)
        {
            pq.emplace(pair.second, pair.first);

        }
        vector<int> answer;
        while(k-->0)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};


// Time Complexity: O(NlogK)
// Space Complexity: O(n)