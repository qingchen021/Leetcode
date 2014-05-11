/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
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
	 ListNode *swapPairs(ListNode *head) {
		 if (head == NULL || head->next == NULL)
			 return head;
		 ListNode dummyNode = ListNode(-1);
		 ListNode * last = &dummyNode, *pre = head, *cur = head->next;
		 while (cur != NULL)
		 {
			 ListNode* tmp = cur->next;
			 cur->next = pre;
			 pre->next = tmp;
			 last->next = cur;

			 if (tmp != NULL && tmp->next != NULL)
			 {
				 last = pre;
				 cur = tmp->next;
				 pre = tmp;
			 }
			 else
			 {
				 cur = NULL;
			 }
		 }
		 return dummyNode.next;
	 }
 };
