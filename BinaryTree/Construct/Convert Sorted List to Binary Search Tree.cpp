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
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	if(head == NULL)
    		return NULL;
        TreeNode * ret = sortedListToBST(head, NULL);
        return ret;
    }

    TreeNode *sortedListToBST(ListNode *start,ListNode *end) 
    {
    		if(start == end) 
    			return NULL;
    		ListNode * mid = FindMiddle(start,end);;
     		TreeNode * midTree = new TreeNode(mid->val); 
     		TreeNode * left = sortedListToBST(start, mid);
     		TreeNode * right = sortedListToBST(mid->next,end);
     		midTree->left = left;
     		midTree->right = right;
     		return midTree;
    }

    ListNode * FindMiddle(ListNode * start, ListNode * end)
    {
    	ListNode * slow = start, * fast = start;
    	while(fast != end)
    	{
    		fast = fast->next;
    		if(fast==end)
    			break;
    		fast = fast->next;
    		slow = slow->next;
       	}
       	return slow;
    }
};