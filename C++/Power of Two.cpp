// Power of Two

// Given an integer, write a function to determine if it is a power of two.


//MY solution

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if( n < 1 )
            return false;
        
        if( n == 1)
            return true;
        
        while(n > 1)
        {
            if(n%2 == 0)
            {
                n /= 2;
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};

// a better solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};