/* Problem Statement: 
Given the root of a binary tree, return the level order traversal of 
its nodes' values. (i.e., from left to right, level by level).
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) 
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()) 
        {
            int levelSize = size(q);
            vector<int> curLevel;
            for(int i = 0; i < levelSize; i++) 
            {
                auto top = q.front();
                q.pop();
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
                curLevel.push_back(top -> val);
            }
            ans.push_back(move(curLevel));
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Compleixty: O(n)