/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
*/

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		if (m == n)
			return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode * first = &dummy;
		for (int i = 1; i < m; i++)
			first = first->next;
		ListNode * last = first;
		for (int i = 1; i <= n - m + 2; i++)
		{
			last = last->next;
			if (last == NULL)
				break;
		}
		ListNode * newSecond = first->next;
		ListNode *newFirst = Reverse(first->next, last);
		first->next = newFirst;
		newSecond->next = last;
		return dummy.next;
	}

	ListNode* Reverse(ListNode * first, ListNode * last)
	{
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