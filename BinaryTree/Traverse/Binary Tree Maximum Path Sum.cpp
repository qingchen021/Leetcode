/*
 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
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
	int sum;
public:
	int maxPathSum(TreeNode *root)
	{
		sum = root->val;
		maxSum(root);
		return sum;
	}
	int maxSum(TreeNode * head)
	{
		//返回的时候只能返回一条边给上层
		//但是计算当前node的时候，需要把两条边算进去。
	    int ret = INT_MIN;
		int left = 0, right = 0;
		if (head->left)
			left = maxSum(head->left);
		if (head->right)
			right = maxSum(head->right);
		int curMax = (left > 0 ? left : 0) + (right > 0 ? right : 0) + head->val;
		int m = left > right?left:right;
		if(m > 0 )
			ret = m + head->val;
		else
			ret = head->val;
		sum = max(curMax, sum);
		return  ret;
	}
};