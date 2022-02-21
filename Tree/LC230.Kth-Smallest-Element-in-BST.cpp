/* Problem Statement:
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) 
of all the values of the nodes in the tree.
*/

class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            if(--k==0)
            {
                break;
            }
            root=root->right;
        }
        return root->val;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n), iterative inorder traversal, but we stop when k = 0