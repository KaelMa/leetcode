//problem
/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/



//mysolution


public class Solution {
    public List<String> anagrams(String[] strs) {
        
        List<String> list = new ArrayList<String>();
        HashMap<String,ArrayList<String>> hashmap =new HashMap<String,ArrayList<String>>();
        for(String str:strs)
        {
            char[] chr = str.toCharArray();
            Arrays.sort(chr);
            String sortStr = new String(chr);
            if(hashmap.containsKey(sortStr))
            {
                hashmap.get(sortStr).add(str);
            }
            else
            {
                ArrayList<String> alist = new ArrayList<String>();
                alist.add(str);
                hashmap.put(sortStr,alist);
            }
            
        }
        
        Set<String> set = hashmap.keySet();
        for(String s:set)
        {
            if(hashmap.get(s).size()>1)
            {
                list.addAll(hashmap.get(s));
            }
        }
        
        return list;
        
        
        
    }
}