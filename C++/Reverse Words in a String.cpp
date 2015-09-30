// Reverse Words in a String

// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.



//My Solution

class Solution {
public:
    void reverseWords(string &s) 
    {
        int l = s.size();
        if(l == 0)
            return;
        
        string result;
        
        int i = l-1;
        while(i>=0)
        {
            while(s[i] == ' ' && i>=0)
                i--;
            if(i < 0)
                break;
            if(!result.empty())
                result.push_back(' ');
                
            string temp;
            while(s[i] !=' ' && i>=0)
                temp.push_back(s[i--]);
            
            std::reverse(temp.begin(),temp.end());
            result.append(temp);
        }
        
        s = result;
        
        
        
    }
};