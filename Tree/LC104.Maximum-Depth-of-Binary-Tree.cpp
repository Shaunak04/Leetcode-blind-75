/* Problem Statement:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the 
longest path from the root node down to the farthest leaf node.
*/

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

// Time complexity: O(n)
// Space complexity: O(n) // considering implicit recursive stack space