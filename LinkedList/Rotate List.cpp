/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

 class Solution {
 public:
	 ListNode *rotateRight(ListNode *head, int k) {
		 if (head == NULL || k == 0)
			 return head;
		 ListNode * newHead = Reverse(head, NULL);
		 ListNode * last = newHead;
		 for (int i = 0; i < k; i++)
		 {
			 if (last == NULL)
			 {
				 last = newHead;
				 last = last->next;
			 }
			 else
			 {
				 last = last->next;
			 }			
		 }
		 ListNode * first = Reverse(newHead, last);
		 ListNode * second = Reverse(last, NULL);
		 newHead->next = second;
		 return first;
	 }

	 ListNode* Reverse(ListNode * first, ListNode * last)
	 {
		 if (first == last || first->next == last)
			 return first;
		 ListNode * pre = first, *cur = first->next;
		 pre->next = NULL;
		 while (true)
		 {
			 ListNode * tmp = cur->next;
			 cur->next = pre;
			 pre = cur;
			 if (tmp == last)
			 {
				 break;
			 }
			 else
			 {
				 cur = tmp;
			 }
		 }
		 return cur;
	 }
 };