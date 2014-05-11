/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		RandomListNode * cur = head;
		while (cur != NULL)
		{
			RandomListNode * node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}
		cur = head;
		while (cur != NULL)
		{
			if (cur->random != NULL)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		cur = head;
		RandomListNode * ret = cur->next;
		while (cur != NULL)
		{
			RandomListNode * tmp = cur->next;
			cur->next = tmp->next;
			cur = tmp->next;
			if (tmp->next != NULL)
				tmp->next = tmp->next->next;
		}
		return ret;
	}
};