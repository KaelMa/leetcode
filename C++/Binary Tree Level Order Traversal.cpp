// Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        
        if(root == nullptr)
            return res;
        
        queue<TreeNode*> tempQueue;
        
        tempQueue.push(root);
        
        while(!tempQueue.empty())
        {
            int count = tempQueue.size();
            vector<int> level;
            while(count > 0)
            {
                TreeNode* node = tempQueue.front();
                tempQueue.pop();
                
                level.push_back(node->val);
                
                if(node->left != nullptr)
                    tempQueue.push(node->left);
                if(node->right !=nullptr)
                    tempQueue.push(node->right);
                
                count--;
            }
            
            res.push_back(level);
        }
        
        return res;
        
        
    }
};