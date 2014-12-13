/**
*
*Given a binary tree, flatten it to a linked list in-place.
*
*For example,
*Given
*
*         1
*        / \
*       2   5
*      / \   \
*     3   4   6
*The flattened tree should look like:
*   1
*    \
*     2
*      \
*       3
*        \
*         4
*          \
*           5
*            \
*             6
*/

//---------------------solution

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    private TreeNode lastVisit = null;
    
    public void flatten(TreeNode root) {
        
        if(root == null)
           return;
           
        TreeNode savedRight = root.right;
        if(lastVisit != null)
        {
            lastVisit.left = null;
            lastVisit.right = root;
        }
        
        lastVisit = root;
        
        flatten(root.left);
        flatten(savedRight);
           

        
    }
}