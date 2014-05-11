/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
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
    bool isBalanced(TreeNode *root) {
    	bool res = true;
        GetDepth(root,0,res);
        return res;
    }

    int GetDepth(TreeNode * root, int curDepth, bool & res)
    {
    	if(!res)
    		return 0;
    	if(root == NULL)
    		return 0;
    	int leftDepth  = 0;
    	if(root->left)
    		leftDepth= GetDepth(root->left, curDepth + 1, res);
    	int rightDepth = 0;
    	if(root->right)
    	 	rightDepth= GetDepth(root->right,curDepth + 1, res);
    	 if(abs(rightDepth - leftDepth) > 1)
    	 	res = false;
    	 return max(rightDepth,leftDepth) + 1;
    }
};