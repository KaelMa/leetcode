// Sort a linked list using insertion sort.


//My solution

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) 
    {
        if(head == null)
           return null;
        
        ListNode cur = head.next;
        while(cur != null)
        {
            ListNode p = head;
            while(p != cur)
            {
                if(p.val > cur.val)
                {
                    int temp = p.val;
                    p.val = cur.val;
                    cur.val = temp;
                }
                p = p.next;
                
            }
            
            cur = cur.next;
        }
        
        return head;
        
    }
}