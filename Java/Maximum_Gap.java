//Problem
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range 
*/




//My Solution
//Bucket Sort

public class Solution {
    public int maximumGap(int[] num) {
        
        if(num == null || num.length <2)
          return 0;
        
        int l = num.length;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        
           
        for(int i : num)
        {
            max = Math.max(max,i);
            min = Math.min(min,i);
        }
        
        int gap = (int)Math.ceil((double)(max-min)/(l-1));
        int maxValue[] = new int[l];
        int minValue[] = new int[l];
        
        Arrays.fill(maxValue,Integer.MIN_VALUE);
        Arrays.fill(minValue,Integer.MAX_VALUE);
        
        for(int i:num)
        {
            int k = (i - min)/gap;
            maxValue[k] = Math.max(i,maxValue[k]);
            minValue[k] = Math.min(i,minValue[k]);
        }
        
        int result = Integer.MIN_VALUE;
        int pre = maxValue[0];
        
        for(int i=0;i<=l-1;i++)
        {
            if(maxValue[i] == Integer.MIN_VALUE || minValue[i]==Integer.MAX_VALUE)
               continue;
               
           result = Math.max(result,minValue[i]-pre);
           
           pre = maxValue[i];
            
        }
        
        return result;
        
    }
    
}