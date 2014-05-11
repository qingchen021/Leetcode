/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> treeStack;
        TreeNode * cur = root;
        TreeNode * pre = NULL;
        vector<int> ret;
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
        		if(cur->right && cur->right != pre )
        		{
        			treeStack.push(cur);        		
        			cur = cur->right;
        		}
        		else
        		{
        			ret.push_back(cur->val);
        			pre = cur;
        			cur = NULL;
        		}
        	}
        }
        return ret;
    }
};