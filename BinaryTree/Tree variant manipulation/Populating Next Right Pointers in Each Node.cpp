/*
 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

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