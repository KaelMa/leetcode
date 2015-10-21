// Valid Parentheses

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


//My solution

class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size() == 0)
            return false;
            
        stack<char> st;
        
        for(int i = 0; i< s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                if((st.top()=='(' && s[i] == ')') || (st.top() == '[' && s[i] ==']') || (st.top() == '{' && s[i] =='}' ) )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
        
        
    }
};