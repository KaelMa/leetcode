
// Interleaving String

// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.



//My solution
//backtracking

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if(l1+l2 != l3)
            return false;
        
        return isInterleaveHelper(s1,0,s2,0,s3,0);
        
        
        
    }
    
    bool isInterleaveHelper(string& s1,int p1,string& s2,int p2,string& s3,int p3)
    {
        if(p3 == s3.length())
            return true;
        if(p1 == s1.length())
            return s3.substr(p3).compare(s2.substr(p2)) == 0? true:false;
        if(p2 == s2.length())
            return s3.substr(p3).compare(s1.substr(p1)) == 0? true:false;
        if(s3[p3] == s2[p2] && s3[p3] == s1[p1] )
            return isInterleaveHelper(s1,p1+1,s2,p2,s3,p3+1) || isInterleaveHelper(s1,p1,s2,p2+1,s3,p3+1) ;
        else if(s3[p3] == s2[p2])
            return isInterleaveHelper(s1,p1,s2,p2+1,s3,p3+1);
        else if(s3[p3] == s1[p1])
            return isInterleaveHelper(s1,p1+1,s2,p2,s3,p3+1);
        else
            return false;
    }
};