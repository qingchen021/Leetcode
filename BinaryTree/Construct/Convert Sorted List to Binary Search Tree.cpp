/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution 
{
public:
    	TreeNode *sortedListToBST(ListNode *head) 
    	{
		if(head == NULL)
			return NULL;
		if(head->next == NULL)
			return new TreeNode(head->val);
		ListNode * slow = head , * fast = head;
		ListNode * pre = NULL;
		while(fast && fast->next && fast->next->next)
		{
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		TreeNode * n = new TreeNode( slow->val);
		if(pre!=NULL)
		{
		    pre->next = NULL;
		    n->left = sortedListToBST(head);
		}
		n->right = sortedListToBST(slow->next);
		return n;		
    	}
	
};