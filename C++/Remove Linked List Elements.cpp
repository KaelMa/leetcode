// Remove Linked List Elements My Submissions Question Solution 
// Total Accepted: 37287 Total Submissions: 142287 Difficulty: Easy
// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.



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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head == nullptr)
            return head;
        
        ListNode *pre = new ListNode(0);
        pre->next = head;
        
        ListNode* res = pre;
        
        ListNode* cur = head;
        
        while(cur != nullptr)
        {
            if(cur->val == val)
            {
                ListNode* temp = cur;
                pre->next = cur->next;
                cur = cur->next;
                
                delete temp;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        
        ListNode* r = res->next;
        delete res;
        
        return r;
        
        
    }
};