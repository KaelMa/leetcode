//Problem
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/


//My Solution
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null )
           return null;
        if(strs.length == 0)
           return "";
        
        int minLength = Integer.MAX_VALUE;
        for(int i=0;i<=strs.length-1;i++)
        {
            if(strs[i].length()<minLength)
               minLength = strs[i].length();
        }
        
        if(minLength == 0)
           return "";

        
        char test;
        StringBuffer result = new StringBuffer();
        
        for(int j =0;j<=minLength-1;j++)
        {
            test = strs[0].charAt(j);
            int k;
            for(k = 0;k<=strs.length-1;k++)
            {
                char t = strs[k].charAt(j);
                if(test != t)
                {
                    break;
                }
                
            }
            
            if(k == strs.length)
                result.append(test);
            else
                break;

        }
        
        return result.toString();

        
    }
}