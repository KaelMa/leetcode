// Add Binary My Submissions Question
// Total Accepted: 61595 Total Submissions: 244313 Difficulty: Easy
// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

// Subscribe to see which companies asked this question


//My solution

class Solution {
public:
    string addBinary(string a, string b)
    {
        if(a.empty() && b.empty())
            return "";
        if(a.empty() || b.empty())
            return a.empty()? b: a;
        
        int i = 0;
        int flag = 0;
        string r ="";
        
        while( i < a.size() || i < b.size() || flag ==1)
        {
            int m = i<a.size()? a[a.size()-1-i]-'0':0;
            int n = i< b.size()? b[b.size()-1-i] -'0':0;
            
            flag += (m + n);
            
            int temp = flag % 2;
            
            r = to_string(temp) + r;
            
            flag /= 2;
            i++;
        }
        
        return r;
        
    }
};