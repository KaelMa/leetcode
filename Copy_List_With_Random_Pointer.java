
/**
*Question Description:
*
*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
*
*Return a deep copy of the list.
*
**/


/**
*My Solution:(Java)
**/



/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        
        if(head==null)
          return head;
          
        RandomListNode cHead = new RandomListNode(head.label);
        HashMap<RandomListNode,RandomListNode> map = new HashMap<RandomListNode,RandomListNode>();
        map.put(head,cHead);
        
        RandomListNode cNode = cHead;
        RandomListNode pNode = head.next;
        while(pNode !=null)
        {
            RandomListNode tempNode = new RandomListNode(pNode.label);
            map.put(pNode,tempNode);
            cNode.next = tempNode;
            cNode = tempNode;
            pNode = pNode.next;

        }
        
        cNode = cHead;
        pNode = head;
        while(pNode !=null)
        {
            cNode.random = map.get(pNode.random);
            cNode = cNode.next;
            pNode = pNode.next;
        }
        
        return cHead;

}
}
