/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum) {
        HasPathSum(root,sum,0);
    }

    bool HasPathSum(TreeNode *root, const int sum,int curSum)
    {
        if(root == NULL) 
        	return false;
        if(root->left == NULL && root->right == NULL)
        	if(curSum + root->val == sum)
        		return true;
        bool left = HasPathSum(root->left,sum,curSum + root->val);
        if(left)
        	 return true;
       	bool right = HasPathSum(root->right,sum, curSum + root->val);
       	if(right)
       		return true;
       	return false;
    }
};