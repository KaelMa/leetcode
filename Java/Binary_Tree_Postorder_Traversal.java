//Problem

/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?*/



//my solution

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
    
    //iterative
    public List<Integer> postorderTraversal(TreeNode root)
    {
        List<Integer> result = new ArrayList<Integer>();  
        if(root==null)
           return result;
           
        Stack<TreeNode> stack =new Stack<TreeNode>();
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode top = stack.peek();
            if(top.left==null && top.right==null)
            {
                result.add(top.val);
                stack.pop();
            }
            if(top.left!=null)
            {
                stack.push(top.left);
                top.left=null;
                continue;
            }
            if(top.right!=null)
            {
                stack.push(top.right);
                top.right=null;
                continue;
            }
        }
        return result;
        
    }
    
}