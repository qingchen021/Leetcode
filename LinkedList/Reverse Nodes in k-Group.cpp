/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
*/

class Solution {
public:
	ListNode *reverseKGroup(ListNode * head, int k) {
		if (head == NULL || k == 1)
			return head;
		ListNode * start = head;
		ListNode * pre = NULL;
		ListNode * ret = NULL;
		while (true)
		{
			ListNode * cur = start;
			int i = 1;
			for (i = 1; i< k; i++)
			{
				if (cur == NULL || cur->next == NULL)
					break;
				cur = cur->next;
			}
			if (i < k)
			{
				if (ret == NULL)
					ret = start;
				if (pre != NULL)
				{
					pre->next = start;
				}
				break;
			}
			else
			{
				ListNode * nextStart = cur->next;
				ListNode * newStart = Reverse(start, cur->next);
				if (ret == NULL)
					ret = newStart;
				if (pre != NULL)
				{
					pre->next = newStart;
				}				
				pre = start;
				start = nextStart;
			}
		}
		return ret;
	}

	ListNode * Reverse(ListNode * first, ListNode * last)
	{
		if (first == last)
			return first;
		ListNode * cur = first;
		ListNode * pre = NULL;
		while (cur != last)
		{
			ListNode * tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};