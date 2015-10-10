// Happy Number
// Total Accepted: 35288 Total Submissions: 107200 Difficulty: Easy

// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Credits:
// Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.



//My solution

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<long> s;
        
        long i = sum(n);
        
        while(i != 1)
        {
            if(s.find(i) != s.end())
            {
                break;
            }
            else
            {
                s.insert(i);
            }
            
            i = sum(i);
        }
        
        if(i == 1)
            return true;
        else
            return false;
        
    }
    
    long sum(int n)
    {
        long count = 0;
        
        int i = 0;
        
        while(n !=0 )
        {
            i = n%10;
            
            count += i*i;
            
            n = n/10;
        }
        
        return count;
    }
    
};