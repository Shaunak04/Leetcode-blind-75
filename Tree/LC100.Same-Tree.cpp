/* Problem statement:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(q==NULL || p==NULL)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
};

// Time complexity: O(max(n,m)), n and m are the number of nodes in p and q
// Space complexity: O(max(n+m)), implicit recusion stack space