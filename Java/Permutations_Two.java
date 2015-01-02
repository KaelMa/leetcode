//Problems
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


//My Solution
//BackTracking

public class Solution {
    public List<List<Integer>> permuteUnique(int[] num) {
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(num == null || num.length == 0)
        {
            return res;
        }
        
        Arrays.sort(num);
        
        recurBackTrace(res,num,new ArrayList<Integer>(),new boolean[num.length]);
        
        return res;
        
    }
    
    private void recurBackTrace(List<List<Integer>> result,int[] num,List<Integer> temp,boolean[] used)
    {
        
        if(temp.size() == num.length)
        {
            result.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int k = 0;k< num.length;k++)
        {
            if(k>0 && !used[k-1] && num[k]==num[k-1])
            {
                continue;
            }
            
            if(!used[k])
            {
                used[k] = true;
                temp.add(num[k]);
                recurBackTrace(result,num,temp,used);
                used[k] = false;
                temp.remove(temp.size()-1);
            }
            
        }
            
    }
}