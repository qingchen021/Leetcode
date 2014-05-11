/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/

class Solution {
#define MAX  2147483647
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode  dummyNode = ListNode(MAX);
		ListNode * last = & dummyNode;
		int size = lists.size();
		if(size == 0)
			return NULL;
		int curIndex = -1;
		do{
			curIndex = -1;
			int curMin = MAX;
			for(int i = 0 ;i < lists.size(); i++)
			{	
				if(lists[i]!=NULL)
				{
					int tmp = lists[i] ->val;
					if( tmp <= curMin)
					{
						curMin = tmp;
						curIndex = i;
					}
				}
			}
			if( curIndex != -1)
			{	
				last->next = lists[curIndex];
				last = last->next;
				lists[curIndex]= lists[curIndex]->next;
			}
		}while(curIndex != -1);
		last->next = NULL;
		return dummyNode.next;
	}
};