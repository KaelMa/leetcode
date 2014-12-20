//Problem
/*Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/


//my Solution

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
    
    public int maxPath = Integer.MIN_VALUE;
    
    //经过root的且最多只经过一边子树最大路径
    public int maxSum(TreeNode root)
    {
        if(root == null)
           return 0;
           
        int value = root.val;
        int temp = root.val;
        int l = 0;
        int r = 0;
        
        if(root.left != null)
        {
           l = maxSum(root.left);
           
           if(l>0)
              temp += l;
             
        }
        if(root.right != null)
        {
           r = maxSum(root.right);
           
           if(r>0)
              temp += r;
        }
        
        //更新最大值  
        //maxPath is the max of {root.val,root.val+lmax, root.val+rmax, root.val + lmax + rmax}        
        if(temp >maxPath)
            maxPath = temp;
        
        //返回值
        //return max of(root.val, root.val+lmax, root.val+rmax)
        return Math.max(value,Math.max(l+value,r+value));
        
    }
    
    public int maxPathSum(TreeNode root) {
        
        if(root == null)
           return 0;
        
        maxSum(root);
        
        return maxPath;
     
        
    }
}