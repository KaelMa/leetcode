// Binary Tree Paths My Submissions Question
// Total Accepted: 20667 Total Submissions: 87978 Difficulty: Easy
// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question



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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        
        if(root == nullptr)
            return res;
        
        recurPath(root,res,to_string(root->val));
        
        return res;
        
    }
    
    void recurPath(TreeNode* root,vector<string>& v,string s)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(s);
            return;
        }
        
        if(root->left != nullptr)
            recurPath(root->left,v,s+"->"+to_string(root->left->val));
        
        if(root->right != nullptr)
            recurPath(root->right,v,s+"->"+to_string(root->right->val));
        
    }
    
    
    
};