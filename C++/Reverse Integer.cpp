// Reverse Integer My Submissions Question
// Total Accepted: 105576 Total Submissions: 450822 Difficulty: Easy
// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

// click to show spoilers.

// Have you thought about this?
// Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



//My solution

class Solution {
public:
    int reverse(int x) 
    {
        long long temp = 0;
        
        while(x != 0)
        {
            int a = x % 10;
            temp = temp*10 + a;
            
            x /= 10;
        }
        
        
        return (temp>INT_MAX || temp < INT_MIN)?0:temp ;
        
    }
};

