/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
	ListNode * cur = &dummy;
	ListNode * head1= l1, * head2 = l2;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->val < head2->val)
		{
			cur->next = head1;
			head1 = head1->next;
		}
		else
		{
			cur->next = head2;
			head2 = head2->next;
		}
		cur = cur->next;		
	}
	while(head1 != NULL)
	{
		cur->next = head1;
		cur = cur->next;
		head1 = head1->next;
	}
	while(head2 != NULL)
	{
		cur->next = head2;
		cur = cur->next;
		head2 = head2->next;
	}
	return dummy.next;
    }
};