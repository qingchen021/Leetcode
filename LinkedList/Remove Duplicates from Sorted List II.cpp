/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL || head->next == NULL)
    		return head;
        ListNode dummy(0);
        ListNode * retCur = &dummy; 
        ListNode * pre = head;
        ListNode * cur = head->next;
        bool repeat = false;
        while(cur)
        {
        	if(cur->val != pre->val)
        	{
        		if(!repeat)
        		{
        			retCur->next = pre;
        			retCur = retCur->next;
        		}
        		repeat = false;
        	}
        	else
        	{
        		repeat = true;
        	}
        	pre = cur;
        	cur = cur->next;
        }
        if(!repeat)
        {
        	retCur->next = pre;
        	retCur = retCur->next;
        }
        retCur->next = NULL;
        return dummy.next;
    }
};