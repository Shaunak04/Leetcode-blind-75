/* Problem Statement:
Given the roots of two binary trees root and subRoot, return true if there is a subtree
of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this 
node's descendants. The tree tree could also be considered as a subtree of itself.
*/

class Solution 
{
public:
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        if(root==NULL || subRoot==NULL)
        {
          return false;
        }
        if(root->val!=subRoot->val) return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        if(root==NULL || subRoot==NULL)
        {
            return false;
        }
        bool cc = check(root, subRoot);
        if(cc) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }
};

// Time Complexity: O(n*n)
// Space Complexity: O(n)