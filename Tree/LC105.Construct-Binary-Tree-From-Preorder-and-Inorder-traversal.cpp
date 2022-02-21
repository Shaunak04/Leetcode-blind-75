/* Problem Statement:
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree
*/

class Solution 
{
private:
    map<int, int> mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        int p=0;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return MakeBT(preorder, inorder, 0, n-1, p);
    }
    
    TreeNode* MakeBT(vector<int>& preorder, vector<int> &inorder, int l, int r, int &idx)
    {
        if(l>r)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        int i = mp[root->val];
        root->left = MakeBT(preorder, inorder, l, i-1, idx);
        root->right = MakeBT(preorder, inorder, i+1, r, idx);
        return root;
    }
};

// Time Complexity: O(n), building the hashmap takes O(n) time, where n = inorder.size()
// Space Complexity: O(n)