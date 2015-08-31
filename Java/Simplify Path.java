// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"


// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".


//My solution

public class Solution {
	
    public String simplifyPath(String path) 
    {
        if(path == null || path.length() == 0)
            return null;
            
        String p = path.replaceAll("////","/");
        
        String[] pArray = p.split("/");
        
        ArrayList<String> list = new ArrayList<String>();
        
        for(String array:pArray)
        {
            if(array.equals(".") || array.equals("") )
               continue;
            else if(array.equals("..") && !list.isEmpty())
            {
                list.remove(list.size()-1);
            }
            else if(array.equals("..") && list.isEmpty())
               continue;
            else
                list.add(array);
        }
        
        StringBuilder result = new StringBuilder();
        
        if(list.isEmpty())
            result.append("/");
        else
         {
             for(String l:list)
             {
                 result.append("/"+l);
             }
         }
         
         return result.toString();
            
            
        
        
    }
}