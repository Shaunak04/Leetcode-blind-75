/* Problem Statement:
Given the root of a binary tree, invert the tree, and return its root.
*/

class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        else
        {
            if(root->left!=nullptr)
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n), considering implicit recursion stack