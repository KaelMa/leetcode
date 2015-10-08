// Remove Duplicates from Sorted List

// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head == nullptr)
            return head;
            
        ListNode* h = head;
        ListNode* p = head->next;
        while(p != nullptr)
        {
            if(h->val == p->val)
            {
                ListNode* temp = p;
                h->next = p->next;
                p = h->next;
                delete temp;
            }
            else
            {
                h = h->next;
                p = p->next;
            }
        }
        
        return head;
        
    }
};