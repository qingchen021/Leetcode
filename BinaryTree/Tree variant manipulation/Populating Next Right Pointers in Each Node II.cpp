/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
        	return ;
        root->next = NULL;
        TreeLinkNode * cur = root;
        TreeLinkNode * nextStart = NULL;
        while(cur)
        {
            TreeLinkNode tmp(0);
        	TreeLinkNode * nextLevelPre =&tmp;
        	while(cur)
        	{
        		while(cur && cur->left == NULL && cur->right == NULL)
        		{
        			cur = cur->next;
        		}
        		if(cur == NULL)
        			break;
        		if(nextStart == NULL)
        		{
        			if(cur->left)
        				nextStart= cur->left;
        			else
        				nextStart = cur->right;
        		}
        		if(cur->left != NULL)
        		{
        			nextLevelPre->next = cur->left;
        			if(cur->right != NULL)
        			{     
        				cur->left ->next = cur->right;   				
        				nextLevelPre = cur->right;        				
        			}
        			else
        			{
        				nextLevelPre = cur ->left;
        			}
        		}
        		else
        		{
        		    nextLevelPre->next = cur->right;
        			nextLevelPre = cur->right;     
        		}
        		cur = cur->next;
        	}
        	cur = nextStart;
        	nextStart = NULL;
        }
    }
};