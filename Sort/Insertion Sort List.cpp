/*
Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head) {
		//注意这个dummyNode
		ListNode dummy(0);
		ListNode * preRet = &dummy;
		ListNode * start = head;
		while (start)
		{
			ListNode tmp(INT_MAX);
			tmp.next = start;
			ListNode * cur = start;
			ListNode * preSmallest = &tmp;
			ListNode * smallest = cur;
			ListNode * pre = &tmp;
			while (cur)
			{
				if (cur->val < smallest->val)
				{
					preSmallest = pre;
					smallest = cur;
				}
				pre = cur;
				cur = cur->next;
			}

			preRet->next = smallest;
			preSmallest->next = preSmallest->next->next;
			preRet = preRet->next;
			preRet->next = NULL;

			start = tmp.next;
		}
		return dummy.next;
	}
};
