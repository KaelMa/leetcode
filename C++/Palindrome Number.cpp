// Palindrome Number

// Determine whether an integer is a palindrome. Do this without extra space.

// click to show spoilers.

// Some hints:
// Could negative integers be palindromes? (ie, -1)

// If you are thinking of converting the integer to string, note the restriction of using extra space.

// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

// There is a more generic way of solving this problem.


class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0 )
            return false;
        
        int r = 0;
        int y = x;
        while( y > 0)
        {
            int t = y%10;
            
            r = r*10+t;
            
            y /= 10;
        }
        
        return r == x ;
        
    }
};