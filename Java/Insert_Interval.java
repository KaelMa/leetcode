/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/



//My solution , O(n)

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        
        if(intervals.isEmpty())
        {
           List<Interval> res = new ArrayList<Interval>();
           res.add(newInterval);
           return res;
        }
        if(newInterval == null)
           return intervals;
           
        int posStart = binarySearchPosition(intervals,newInterval,true);
        int posEnd = binarySearchPosition(intervals,newInterval,false);
        
        
        if(posStart==0 || newInterval.start > intervals.get(posStart-1).end)
        {
            if(posEnd == intervals.size() || newInterval.end < intervals.get(posEnd).start )
            {
                intervals.add(posStart,newInterval);
                if(posStart < posEnd)
                {
                  for(int i =posStart;i< posEnd;i++)
                  {
                      intervals.remove(posStart+1);
                  }
                }
            }
            else
            {
                Interval temp = new Interval(newInterval.start,intervals.get(posEnd).end);
                intervals.add(posStart,temp);
                
                if(posStart <= posEnd )
                {
                  for(int i =posStart;i<= posEnd;i++)
                  {
                      intervals.remove(posStart+1);
                  }
                }
                
            }
        }
        else
        {
            if(posEnd==intervals.size() || newInterval.end < intervals.get(posEnd).start)
            {
                intervals.get(posStart-1).end = newInterval.end;
                if(posStart < posEnd)
                {
                    for(int i=posStart;i< posEnd;i++)
                    {
                        intervals.remove(posStart);
                    }
                }
            }
            else
            {
                intervals.get(posStart-1).end = intervals.get(posEnd).end;
                if(posStart<=posEnd)
                {
                    for(int i = posStart;i<= posEnd;i++)
                    {
                        intervals.remove(posStart);
                    }
                }
            }
        }
        
        return intervals;
        
        
           
    }
        
     public int binarySearchPosition(List<Interval> intervals,Interval newInterval,boolean start)
     {
         int m = 0;
         int n = intervals.size()-1;
         int p = (m+n)/2;
         
         while(m <= n)
         {
             if(start)
             {
                 if(newInterval.start == intervals.get(p).start)
                 {
                     return p+1;
                 }
                 if(newInterval.start > intervals.get(p).start)
                 {
                     m = p+1;
                 }
                 else
                 {
                     n = p-1;
                 }
                 
                 p=(m+n)/2;
             }
             else
             {
                if(newInterval.end == intervals.get(p).end)
                 {
                     return p+1;
                 }
                 
                if(newInterval.end > intervals.get(p).end)
                 {
                     m = p+1;
                 }
                 else
                 {
                     n = p-1;
                 }
                 
                 p=(m+n)/2;
                 
             }
         }
         
         return m;
     }
           
     
}