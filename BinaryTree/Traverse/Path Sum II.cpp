/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<int> steps;
		vector<vector<int> > res;
		pathSum(root, sum, steps, res);
		return res;
	}

	void pathSum(TreeNode * root, int sum, vector<int> & steps, vector<vector<int> > & res)
	{
		if (root == NULL)
			return;
		steps.push_back(root->val);
		if (sum - root->val == 0 && root->left == NULL && root->right == NULL)
		{
			res.push_back(steps);
		}
		pathSum(root->left, sum - root->val, steps, res);
		pathSum(root->right, sum - root->val, steps, res);
		steps.pop_back();
	}
};