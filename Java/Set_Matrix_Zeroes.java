//Problem
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/




//My solution
//space complexity O(1)
//时间复杂度为常数问题：1.考虑需要常数个额外空间 2.利用自身的空间来保存中间结果。
//这题利用第一行和第一列来保存中间结果。

public class Solution {
    public void setZeroes(int[][] matrix) {
        
        boolean r = false;
        boolean c = false;
        
        for(int i =0;i<matrix.length;i++)
        {
            if(matrix[i][0] == 0)
            {
                c = true;
                break;
            }
        }
        
        for(int j =0;j<matrix[0].length;j++)
        {
            if(matrix[0][j] == 0)
            {
                r = true;
                break;
            }
        }
        
        if(matrix.length > 1 && matrix[0].length >1)
        {
        for(int i =1;i< matrix.length;i++)
           for(int j =1;j< matrix[0].length;j++)
           {
               if(matrix[i][j] == 0)
               {
                   matrix[0][j] = 0;
                   matrix[i][0] = 0;
               }
           }
        
        for(int i = 1;i<matrix.length;i++)
           for(int j =1;j<matrix[i].length;j++)
           {
               if(matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                   matrix[i][j] = 0;
               }
           }
           
        }
        
        if(r)
        {
            for(int j=0;j<matrix[0].length;j++)
            {
                matrix[0][j] = 0;
            }
        }
        
        if(c)
        {
            for(int i =0;i<matrix.length;i++)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
}