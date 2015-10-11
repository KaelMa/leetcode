// Plus One

// Given a non-negative number represented as an array of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.



//My solution

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        if(digits.size() == 0)
            return digits;
        
        bool flag = true;
        for(int i = digits.size()-1; i>=0 ; i--)
        {
            if(flag)
            {
                if(digits[i] == 9)
                {
                    digits[i] = 0;
                    flag = true;
                }
                else
                {
                    digits[i] += 1;
                    flag = false;
                }
            }
        }
        
        if(digits[0] == 0 )
            digits.insert(digits.begin(),1);
        
        return digits;
        
    }
};