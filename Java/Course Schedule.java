// Course Schedule

// There are a total of n courses you have to take, labeled from 0 to n - 1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// For example:

// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.


//My Solution
//topologic sort
//DFS also works

public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) 
    {
        if(numCourses == 0)
           return false;
           
        int count = 0;   
        int[] inDegree = new int[numCourses];
        boolean[] inDegreeUsed = new boolean[numCourses];
        for(int i= 0;i< numCourses; i++)
        {
            inDegree[i] = 0;
            inDegreeUsed[i] = false;
        }
        
        for(int i = 0;i<prerequisites.length;i++)
        {
            int j = prerequisites[i][0];
            inDegree[j]++;
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        for(int i=0;i< numCourses;i++)
        {
            if(inDegree[i] == 0)
            {
                list.add(i);
                inDegreeUsed[i] = true;
                count++;
            }
        }
        
        while(!list.isEmpty())
        {
            int t = list.remove(0).intValue();
            
            for(int i = 0;i<prerequisites.length;i++)
            {
                if(t == prerequisites[i][1])
                    inDegree[prerequisites[i][0]]--;
            }
            
            for(int i =0; i< numCourses;i++)
            {
                if(inDegree[i] == 0 && !inDegreeUsed[i])
                {
                    list.add(i);
                    inDegreeUsed[i] = true;
                    count++;
                }
            }
        }
        
        if(count == numCourses)
           return true;
        else
           return false;
        
    }
}