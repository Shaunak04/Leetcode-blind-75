/* Problem Statement:
Given an array of strings strs, group the anagrams together. You can return the answer 
in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word 
or phrase, typically using all the original letters exactly once.
*/
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, int> _map;
        vector<vector<string>> ans;
        for(string s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(_map.count(tmp) == 0)
            {
                ans.push_back(vector<string>{s});
                _map[tmp] = ans.size()-1;
            } 
            else
            {
                ans[_map[tmp]].push_back(s);
            }
        }
        return ans;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: o(n)