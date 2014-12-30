//Problem
/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/



//My Solution
//DP

public class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0)
           return null;
        
        if(s.length()==1)
           return s;
        
        int l = s.length();
        boolean[][] c = new boolean[l][l];
        
        for(int i=0;i<=l-1;i++)
           for(int j =0;j<=l-1;j++)
           {
               if(i>=j)
                 c[i][j] = true;
               else
                 c[i][j] = false;
           }
           
        int maxLen = 0;
        int left=0;
        int right=0;
        
        for(int k=2;k<=l;k++)
        {
            for(int i=0;i<=l-k;i++)
            {
                int j = i+k-1;
                if(s.charAt(i) == s.charAt(j))
                {
                    c[i][j] = c[i+1][j-1];
                    
                    if(c[i][j])
                    {
                      if(k>=maxLen)
                      {
                        maxLen = k;
                        left=i;
                        right=j;
                      }
                    }
                
                }
                else
                {
                    c[i][j] = false;
                }
            }
        }
        
        return s.substring(left,right+1);
    }
}