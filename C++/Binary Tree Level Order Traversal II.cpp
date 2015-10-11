// Binary Tree Level Order Traversal II

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


//My solution
//level order traversal

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> re;
        
        if(root == nullptr)
            return re;
        
        queue<TreeNode*> q;
        q.push(root);
        int count = q.size();
        vector<int> level;
        
        while(count > 0 )
        {
            TreeNode* temp = q.front();
            level.push_back(temp->val);
            q.pop();
            
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
            
            count--;
            
            if(count == 0)
            {
                re.insert(re.begin(),level);
                level.clear();
                count = q.size();
            }
        }
        
        return re;
        
        
        
    }
};