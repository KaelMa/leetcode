//Problem
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/



//My Solution

public class Solution {
    public int largestRectangleArea(int[] height) {
        if(height ==null || height.length == 0)
           return 0;
           
        height = Arrays.copyOf(height,height.length+1);
        
        Stack<Integer> s = new Stack<Integer>();
        
        int sum = 0;
        
        for(int i=0;i<=height.length-1;i++)
        {
            if(s.isEmpty() || height[i]>height[s.peek()] )
               s.push(i);
               
            else
            {
                int temp = s.pop();
                sum = Math.max(sum,height[temp]*(s.empty()?i:i-s.peek()-1));
                i--;
                
            }
        }
        return sum;
      
    }
    
}