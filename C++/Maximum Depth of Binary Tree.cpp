// Maximum Depth of Binary Tree

// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


//My solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return l>r?l+1:r+1;
        
    }
};