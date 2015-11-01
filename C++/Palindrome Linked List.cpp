// Palindrome Linked List My Submissions Question
// Total Accepted: 25431 Total Submissions: 104985 Difficulty: Easy
// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

// Subscribe to see which companies asked this question


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
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr)
        {
            if(fast->next != nullptr)
                fast = fast->next->next;
            else
                fast = fast->next;
                
            slow = slow->next;
        }
        
        ListNode* rHead = reverseLink(slow);
        
        while(rHead != nullptr)
        {
            if(rHead->val != head->val)
                return false;
            else
            {
                rHead = rHead->next;
                head = head->next;
            }
        }
        
        return true;
        
    }
    
    ListNode* reverseLink(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* lat = nullptr;
        
        while(head != nullptr)
        {
            lat = head->next;
            head->next = pre;
            
            pre = head;
            head = lat;
        }
        
        return pre;
    }
};