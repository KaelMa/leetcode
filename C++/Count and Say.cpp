// Count and Say My Submissions Question Solution 
// Total Accepted: 59000 Total Submissions: 225655 Difficulty: Easy
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.



//My solution

class Solution {
public:
    string countAndSay(int n) 
    {
        if(n < 1 )
            return "";
        
        string s = "1";
        if(n == 1)
            return s;
        
        for(int i = 2; i<=n;i++)
        {
            string temp;
            
            char c = s[0];
            int j = 1;
            int count = 1;
            
            while(j< s.size())
            {
                if(s[j] != c)
                {
                    temp += to_string(count) + c;
                    
                    c = s[j];
                    count = 1;
                    
                }
                else
                {
                    count++;
                }
                
                j++;
            }
            
            temp += to_string(count) + c;
            s = temp;
        }
        
        return s;
        
    }
};