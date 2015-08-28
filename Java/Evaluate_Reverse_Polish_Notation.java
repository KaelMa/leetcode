// Evaluate Reverse Polish Notation

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


// MySolution:


public class Solution {
    public int evalRPN(String[] tokens) 
    {
        if(tokens == null)
        {
            return 0;
        }
        
        ArrayDeque<Integer> numbers = new ArrayDeque<Integer>();
        for(String token:tokens)
        {
            if(token.equals("+"))
            {
                int b = numbers.pop().intValue();
                int a = numbers.pop().intValue();
                
                numbers.push(a+b);
                
            }
            else if(token.equals("-"))
            {
                int b = numbers.pop().intValue();
                int a = numbers.pop().intValue();
                
                numbers.push(a-b);
            }
            else if(token.equals("*"))
            {
                int b = numbers.pop().intValue();
                int a = numbers.pop().intValue();
                
                numbers.push(a*b);
            }
            else if(token.equals("/"))
            {
                int b = numbers.pop().intValue();
                int a = numbers.pop().intValue();
                
                numbers.push(a/b);
            }
            else
            {
                numbers.push(Integer.valueOf(token));
            }
        }
        
        return numbers.pop().intValue();
        
    }
}

