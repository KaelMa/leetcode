// Reverse Linked List

// Reverse a singly linked list.


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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == nullptr)
            return head;
        
        ListNode* p = head->next;
        ListNode *pre = head;
        pre->next = nullptr;
        
        while(p != nullptr)
        {
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        
        return pre;
        
    }
};