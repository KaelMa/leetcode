
// Length of Last Word

// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.



//My solution

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        if(s.size() == 0)
            return 0;
        
        int i = s.size()-1;
        int count = 0;
        if(i>=0)
        {
            while(s[i] ==' ' && i>=0)
            {
                i--;
            }
            
            if(i < 0)
                return 0;
            
            while(s[i] != ' ' && i>=0)
            {
                i--;
                count++;
            }
            
        }
        
        return count;
        
    }
};