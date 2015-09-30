// Longest Valid Parentheses

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


//My Solution

class Solution {
public:
    int longestValidParentheses(string s)
    {
        if(s.size() == 0)
            return 0;
        
        int count = 0;
        stack<int> st;

        for(int i = 0; i< s.size();i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() && s[st.top()] =='(' )
                {
                    st.pop();
                    if(st.empty())
                        count = i+1;
                    else
                        count = max(count,i-st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        
        return count;
        
    }
};