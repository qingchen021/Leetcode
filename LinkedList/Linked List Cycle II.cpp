/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
 //思路是，从相遇的点和开头的点，一起开始走，直到相遇，就是该环的起始点。
 //详细再这边http://blog.csdn.net/kenden23/article/details/13871699
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode * faster = &dummyNode, * slow = &dummyNode;
        while(faster != NULL && slow != NULL)
        {
        	for(int i = 0 ;i < 2;i++)
        	{
        		faster = faster->next;
        		if(faster == NULL)
        			return NULL;
        	}
        	slow = slow->next;
        	if(faster == slow)
        	    break;
        }
        if(faster == NULL || slow == NULL)
        	return NULL;
        ListNode * same = & dummyNode;
        while(faster != same)
        {
        	faster = faster->next;
        	same = same->next;
        }
        return same;
    }
};