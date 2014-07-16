/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
	if(size == 0)
		return NULL;
	while(size>1)
	{
		int n = (size+1)/2;
		for(int i = 0;i < n;i++)
		{
			lists[i] = merge(lists[i],lists[size-i-1]);
		}
		size = n;
	};
	return lists[0];
    }
    ListNode * merge(ListNode * first, ListNode *second)
   {
	if(first == second)
		return first;
	ListNode dummyNode (INT_MIN), * pre;
	pre = &dummyNode;
	while(first && second)
	{
		if(first->val > second->val)
		{
			pre->next = second;
			second= second->next;
		}
		else 
		{
			pre->next = first;
			first = first->next;	
		}
		pre = pre->next;
	}
	if(first)
	{
		pre->next = first;
	}
	if(second)
	{
		pre->next = second;
	}
	return dummyNode.next;
   }
};