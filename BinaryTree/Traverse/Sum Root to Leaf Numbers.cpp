/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
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
    int sumNumbers(TreeNode *root) {
    	int ret = 0;
    	if(root == NULL) 
    		return ret;
        sumNumbers(root, 0, ret);
        return ret;
    }

    void sumNumbers(TreeNode * root, int parent, int & ret)
    {
    	if(root->left == NULL && root->right == NULL)
    	{
    	    //注意下，这个是叠加的
    		 ret += parent * 10 + root->val;
    	}
    	else
    	{
    		int curParent = parent * 10 + root->val;
    		if(root->left)
    			sumNumbers(root->left, curParent, ret);
    		if(root->right)
    			sumNumbers(root->right, curParent, ret);
    	}
    }
};