// Interleaving String My Submissions Question Solution 
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.



//My solution
// dynamic programming

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) 
    {
        if(s1.length() + s2.length() != s3.length())
            return false;
        if(s1.length() ==0)
            return s2.equals(s3);
        if(s2.length() == 0)
            return s1.equals(s3);
        
        int m = s1.length();
        int n = s2.length();
        
        boolean[][] dp = new boolean[m+1][n+1];
        
        dp[0][0] = true;
        
        for(int i = 1;i<=m;i++)
        {
            if(s1.substring(0,i).equals(s3.substring(0,i)))
                dp[i][0] = true;
            else
                dp[i][0] = false;
        }
        
        for(int j = 1;j<=n;j++)
        {
            if(s2.substring(0,j).equals(s3.substring(0,j)))
                dp[0][j] = true;
            else
                dp[0][j] = false;
        }
        
        for(int i =1;i<=m;i++)
            for(int j = 1; j<= n;j++)
            {
                char c1 = s1.charAt(i-1),c2 = s2.charAt(j-1),c3 = s3.charAt(i+j-1);
                if(c1 == c3 && c2 == c3)
                {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else if(c1 == c3)
                    dp[i][j] = dp[i-1][j];
                else if(c2 == c3)
                    dp[i][j] = dp[i][j-1];
            }
            
            
        return dp[m][n];
        
        
        
    }
}