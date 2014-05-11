/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
    	if(root == NULL)
    		return 0;
    	int res = INT_MAX;
        minDepth(root,1, res);
        return res;
    }

    void minDepth(TreeNode *root, int dep, int & minDep) 
    {
        if(root->left == NULL && root ->right == NULL)
        {
        	minDep = min(dep, minDep);
        	return ;
        }
        else
        {
        	if(root->left)
        		minDepth(root->left, dep+1,minDep );
        	if(root->right)
        		minDepth(root->right, dep+1,minDep );

        }
    }
};