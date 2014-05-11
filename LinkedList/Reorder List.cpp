/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

 class Solution 
 {
 public:
	 void reorderList(ListNode *head)
	 {
		ListNode * second = FindMiddleAndCut(head, NULL);
		if(second != NULL)
		{
			ListNode  dummy(0);
			ListNode * pre = &dummy;
			ListNode * first = head;
			while(first)
			{
				pre->next = first;
				if(second)
				{
					ListNode * nextFirst = first->next;
					ListNode * nextSecond = second->next;
					first->next = second;
					pre = second;
					pre->next = NULL;
					second = nextSecond;
					first = nextFirst;
				}
				else
				{
					first->next = NULL;
				}
			}
		}
	 }

	 ListNode * FindMiddleAndCut(ListNode * head, ListNode * end)
	 {
	 	if(head == end)
	 		return NULL;
	 	ListNode dummy(0);
	 	dummy.next = head;
	 	ListNode * first = & dummy, *second = & dummy;
	 	while(first && second && second->next)
	 	{
	 		first = first ->next;
	 		second = second->next;
	 		second = second->next;
	 	}
	 	ListNode * tmp = first->next;
	 	first->next = NULL;
	 	return tmp;
	 }
};