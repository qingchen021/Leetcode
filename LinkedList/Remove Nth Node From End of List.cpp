/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if( n == 0 ) 
        	return head;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode * last = &dummyNode;
        ListNode *  before = &dummyNode;
        for(int i = 0 ;i < n ;i++)
        {
        	last = last->next;
        }
        while(last->next)
        {
        	last = last->next;
        	before = before->next;
        }
        before->next = before->next->next;
        return dummyNode.next;
    }
};