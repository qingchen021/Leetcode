/*
 Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
*/
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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode * slow = & dummy, * fast = & dummy;
        while(slow&&fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                return false;
            fast = fast->next;
            if(slow == fast)
                return true;
        }
    }

};