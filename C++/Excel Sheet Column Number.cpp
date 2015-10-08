// Excel Sheet Column Number

// Related to question Excel Sheet Column Title

// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 

//     


// My solution

class Solution {
public:
    int titleToNumber(string s)
    {
        if(s.length() == 0)
            return 0;
        
        int base = 1;
        int number = 0;
        for(int i = s.length()-1;i>=0;i--)
        {
            int j = s[i] -'A'+1;
            
            number += j*base;
            
            base *= 26; 
        }
        
        return number;
        
    }
};