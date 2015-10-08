// Climbing Stairs

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


//My solution

class Solution {
public:
    int climbStairs(int n) 
    {
        // f(n) = f(n-1)+f(n-2)
        int i = 1;
        int j = 2;
        if(n == 1)
            return i;
        if(n == 2)
            return j;
        
        int r = 0;
        for(int k = 3;k<=n;k++)
        {
            r = i+j;
            i=j;
            j=r;
        }
        
        return r;
    
        
    }
};
