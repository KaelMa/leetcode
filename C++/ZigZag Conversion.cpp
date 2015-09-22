// ZigZag 
// Total Accepted: 57675 Total Submissions: 267506 Difficulty: Easy
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".



//My solution

class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s;
            
        string result;
        if(s.length() == 0)
            return result;
        
        int t = 2*numRows - 2;
        for(int i = 0; i< numRows;i++)
            for(int j = i; j< s.length(); j += t)
            {
                result.append(1,s[j]);
                
                if(j%t > 0 && j%t < numRows-1 )
                {
                    int k = j + t -2*i;
                    if(k < s.length())
                        result.append(1,s[k]);
                }
                
            }
        
        return result;
    }
};