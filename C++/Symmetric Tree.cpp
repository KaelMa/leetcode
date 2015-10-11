// Symmetric Tree

// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3


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
    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        
        TreeNode *p = root->left;
        TreeNode *q = root->right;
        
        if(p == nullptr && q == nullptr)
            return true;
        
        if( (p == nullptr && q!= nullptr) || (p!= nullptr && q==nullptr) )
            return false;
        
        return isSubSymmetric(p,q);
    }
    
    bool isSubSymmetric(TreeNode* p, TreeNode* q)
    {
        bool r = true;
        while(p != nullptr && q != nullptr)
        {
            if(p->val != q->val)
                return false;
            else
            {
                r = isSubSymmetric(p->left,q->right);
                if (!r) {
                    return r;
                }

                p = p->right;
                q = q->left;
                
            }
            
        }
        
        if(p == nullptr && q == nullptr)
            return true;
        
        if( (p == nullptr && q!= nullptr) || (p!= nullptr && q==nullptr) )
            return false;
        
        return r;
    }
    
};