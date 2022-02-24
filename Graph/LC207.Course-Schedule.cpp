/* Problem Statement:
There are a total of numCourses courses you have to take, labeled from 0 to 
numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take 
course 1. Return true if you can finish all courses. Otherwise, return false.
*/

class Solution 
{
public:
    bool checkCycle(int node, vector<vector<int>>& graph, int vis[], int dfsvis[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it, graph, vis, dfsvis)) return true;
            }
            else if(dfsvis[it]==1) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int vis[numCourses];
        int dfsvis[numCourses];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        
        vector<vector<int>> graph(numCourses);
        for(auto &e:prerequisites)
        {
            graph[e[0]].push_back(e[1]);
        }
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i, graph, vis, dfsvis))
                {
                    return false;
                }
            }
        }
        return true;
    }   
};

// Time Complexity: 
// Space Complexity: 