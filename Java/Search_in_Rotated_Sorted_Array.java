//Problem
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

//tips
//如果A[m] > A[right] 那么数组的右边一定是有序的
//反之，那么数组的左边一定是有序的
//所以每次可以抛掉一半长度

//My Solution

public class Solution {
    public int search(int[] A, int target) {
        if(A==null || A.length==0)
           return -1;
        
        int left = 0;
        int right = A.length-1;
        int m;
        
        while(left <= right)
        {
            m = (left+right)/2; 
            if(target == A[m])
              return m;
            if(A[m] < A[right])
            {
                if(target > A[m] && target <= A[right])
                   left = m+1;
                else
                   right = m-1;
            }
            else
            {
                if(target < A[m] && target >= A[left])
                   right = m-1;
                else
                   left = m+1;
            }
            
        }
        
        return -1;
        
    }
}