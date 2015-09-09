// Valid Palindrome
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.


//My solution

public class Solution {
    public boolean isPalindrome(String s) 
    {
        if(s == null || s.length() == 0)
             return true;
             
        String t = s.toLowerCase();
        
        int low = 0;
        int high = s.length()-1;
        
        while(low < high)
        {
            if( (t.charAt(low) < '0' || t.charAt(low) >'9') && (t.charAt(low) <'a' || t.charAt(low) >'z')) 
            {    
                low++;
                continue;
            }
            if( (t.charAt(high) < '0' || t.charAt(high) >'9') && (t.charAt(high) <'a' || t.charAt(high) >'z') )
            {    
                high--;
                continue;
            }
            
            if( t.charAt(low) == t.charAt(high))
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
}