// Pascal's Triangle

// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


//My solution

public class Solution {
    
    public List<List<Integer>> generate(int numRows) 
    {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        if(numRows == 0)
           return result;
        
        for(int i = 1; i<= numRows; i++)
        {
            ArrayList<Integer> list = new ArrayList<Integer>(i);
            
            if(i == 1)
            {
                list.add(1);
            }
            else
            {
                list.add(0,1);
    
                for(int j = 1; j < i-1 ;j++)
                {
                    int temp = result.get(i-2).get(j-1)+result.get(i-2).get(j);
                    list.add(j,temp);
                }
                
                list.add(1);
            
            }
            
            result.add(i-1,list);
            
        }
        
        return result;
        
    }
}