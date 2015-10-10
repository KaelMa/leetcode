// Merge Two Sorted Lists
// Total Accepted: 83309 Total Submissions: 252945 Difficulty: Easy
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        ListNode* p = new ListNode(0);
        ListNode* q = p;
        
        while(l1!= nullptr && l2!= nullptr)
        {
            if(l1->val <= l2->val)
            {
                p->next =l1;
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        
        if(l1 == nullptr)
            p->next = l2;
        else
            p->next = l1;
            
        ListNode* r = q->next;
        delete q;
        
        return r;
            
        
    }
};