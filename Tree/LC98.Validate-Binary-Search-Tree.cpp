/* Problem Statement:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

class Solution 
{
public:
    
    bool isValid(TreeNode* root, long minval, long maxval)
    {
        if(root==nullptr) return true;
        if(root->val >= maxval || root->val<=minval) return false;
        return isValid(root->left, minval, root->val) || isValid(root->right, root->val, maxval);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};


// Time Complexity: O(n)
// Space Complexity:  O(n)