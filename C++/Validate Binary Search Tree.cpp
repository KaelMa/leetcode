// Validate Binary Search Tree

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root)
    {
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;
        else if(NULL != root->left && NULL ==root->right&&root->left->val < root->val )
        {
            bool isLeft = isLeftMin(root);
            return  isLeft & isValidBST(root->left);
        }
        else if(nullptr != root->right &&NULL==root->left && root->right->val > root->val)
        {
            bool isRight = isRightMax(root);
            return isRight&isValidBST(root->right);
        }
        else if(nullptr !=root->left && nullptr !=root->right && root->val > root->left->val && root->val < root->right->val)
        {
            bool isLeft1 = isValidBST(root->left);
            bool isLeft2 = isLeftMin(root);
            bool isLeft = isLeft1 & isLeft2;
            
            bool isRight1 =isValidBST(root->right);
            bool isRight2 = isRightMax(root);
            bool isRight = isRight1&isRight2;
            
            return isLeft & isRight;
        }
        else
            return false;
        
    }
    
    bool isLeftMin(TreeNode* root)
    {
        TreeNode* p = root->left;
        if(p->right == NULL)
            return true;
        
        while (p->right !=NULL)
        {
            p = p->right;
        }
        return p->val<root->val? true:false;
    }
    
    bool isRightMax(TreeNode* root)
    {
        TreeNode* p = root->right;
        if(p->left == NULL)
        {
            return true;
        }
        
        while (p->left !=NULL)
        {
            p= p->left;
        }
        return p->val > root->val? true:false;
    }
};