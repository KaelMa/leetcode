// Remove Nth Node From End of List

// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.


//My solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == nullptr)
            return head;
        
        ListNode* p = head;
        ListNode* q = nullptr;
        int count = 0;
        while(p != nullptr)
        {
            count++;
            
            if(count == n+2)
            {
                q = head;
            }
            
            p = p->next;
            
            if(q != nullptr)
                q = q->next;
        }
        
        if(count == n)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(count == n+1)
        {
            ListNode* temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        if(q != nullptr)
        {
            ListNode* temp = q->next;
            q->next = temp->next;
            
            delete temp;
        }
        
        return head;
        
        
        
        
    }
};