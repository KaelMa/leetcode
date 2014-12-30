//Problem
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/



//My Solution
public class Solution {
    public int[] searchRange(int[] A, int target) {
        
        if(A == null || A.length == 0)
           return null;
        
        int[] res = new int[2];   
        int p = binarySearch(A,target,0,A.length-1);
        if(p < 0)
        {
            Arrays.fill(res,-1);
        }
        else
        {
            int start = p;
            int end = p;
            while(start>=0 && A[start]==target)
                 start--;
            while(end<=A.length-1 && A[end]==target)
                 end++;
            
            res[0] = ++start;
            res[1] = --end;
        }
        
        return res;
    }
    
    public int binarySearch(int[] A,int target,int start,int end)
    {
        
        int p = (start+end)/2;
        if(start > end)
           return -1;
        if(A[p] == target)
           return p;
        if(A[p] < target)
           return binarySearch(A,target,p+1,end);
        else
           return binarySearch(A,target,start,p-1);
    }
}