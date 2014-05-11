/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> treeStack;
        TreeNode * cur = root;
        vector<int> ret;
        if(root == NULL)
        	return ret;
        while(cur || !treeStack.empty())
        {
        	if(cur)
        	{
        		while(cur)
        		{
        			treeStack.push(cur);
        			cur = cur->left;
        		}
        	}
        	else
        	{
        		cur = treeStack.top();
        		treeStack.pop();
        		ret.push_back(cur->val);
        		cur = cur->right;
        	}
        }
    }
};