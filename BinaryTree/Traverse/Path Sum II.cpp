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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root == NULL)
        	return res;
        vector<int> steps;
        pathSum(root, sum, 0, steps, res);
        return res;
    }

    void pathSum(TreeNode * root, const int sum, int curSum, vector<int> & steps,vector<vector<int> > & res)
    {
    	if(root == NULL)
    		return;
    	if(root->left == NULL && root->right == NULL)
    	{
    		if(root->val + curSum == sum)
    		{
    		    steps.push_back(root->val);
    		    res.push_back(steps);
    		    steps.pop_back();
    		}
    		return;
    	}
    	steps.push_back(root->val);
    	pathSum(root->left, sum, curSum+ root->val,steps,res);
    	pathSum(root->right, sum, curSum + root->val, steps,res);
    	steps.pop_back();
    }
};