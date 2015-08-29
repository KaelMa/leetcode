// Factorial Trailing Zeroes

// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.


//My solution

public class Solution {
    public int trailingZeroes(int n) 
    {
        if( n < 0)
           return -1;
        
        int count = 0;
        for(int i= n/5; i>=1; i = i/5)
        {
            count += i;
        }
        
        return count;
        
    }
}