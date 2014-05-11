/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
	ListNode *partition(ListNode *head, int x) 
	{
		ListNode dummySmall(0), dummyBig(0);
		ListNode * preSmall = & dummySmall, *preBig = & dummyBig;
		while(head)
		{
			ListNode * tmp = head->next;
			if(head->val < x)
			{
				preSmall->next = head;
				preSmall = preSmall->next;
			}
			else
			{
				preBig ->next = head;
			    preBig = preBig->next;
			}
			head->next = NULL;
			head = tmp;
		}
		preSmall->next = dummyBig.next;
		return dummySmall.next;
	}
};