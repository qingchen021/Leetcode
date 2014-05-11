/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode  dummy(0);
		dummy.next = head;
		ListNode * slow = &dummy, *fast = &dummy;
		//here need to check fast->next != NULL
		while (slow && fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
		}
		ListNode * another = slow->next;
		slow->next = NULL;
		ListNode * first = sortList(head);
		ListNode * second = sortList(another);
		ListNode * pre = &dummy;
		while (first && second)
		{
			if (first->val < second->val)
			{
				pre->next = first;
				first = first->next;
			}
			else
			{
				pre->next = second;
				second = second->next;
			}
			pre = pre->next;
		}
		if (first)
			pre->next = first;
		if (second)
			pre->next = second;
		return dummy.next;
	}

};