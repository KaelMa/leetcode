
// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]



//My Solution
//BackTrack iterative implementation

public class Solution {
    
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        
        if(nums == null || nums.length == 0)
           return list;
           
        int n = nums.length;
        int k = 0,i=0;
        int[] t = new int[n];
        int[] s = new int[n];
        Arrays.fill(t,Integer.MAX_VALUE);
        
        ArrayList<Integer> nArray = new ArrayList<Integer>();
        list.add(nArray);
        
        while( k < n)
        {
            while(i < n)
            {
                if(valid(k,i,t,nums))
                {
                    t[k] = nums[i];
                    s[k] = i;
                    
                    //save t[k] in list
                    ArrayList<Integer> temp = new ArrayList<Integer>();
                    for(int j = 0; j<=k;j++)
                    {
                        temp.add(t[j]);
                    }
                    list.add(temp);
                    
                    break;
                    
                }
                else
                {
                    i++;
                }
            }
            
            if(t[k] == Integer.MAX_VALUE )
            {
                if(k == 0)
                   break;
                else
                {
                    k--;
                    i = s[k]+1;
                    t[k] = Integer.MAX_VALUE;
                        
                    continue;
                }
                
            }
            
            if(k == n-1)
            {
                i = s[k]+1;
                t[k] = Integer.MAX_VALUE;
                continue;
            }
            
            k++;
            i=0;
            
        }
        
        return list;
        
    }
    
    private boolean valid(int k,int i,int t[],int nums[])
    {
        for(int j= 0; j< k;j++)
        {
            if(nums[i] <= t[j])
               return false;
        }
        
        return true;
    }
}
