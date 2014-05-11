/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        stack<vector<int> > treeStack;
        queue<TreeNode*> que;
        vector<vector<int> > ret;
        if(root==NULL) return ret;
        vector<int> curLevel;
        que.push(root);
        que.push(NULL);
        while(!que.empty())
        {
        	if(que.front() == NULL)
        	{
        		que.pop();
        		if(!que.empty())
        		{
        			que.push(NULL);
        		}
        		treeStack.push(curLevel);
        		curLevel.clear();
        	}
        	else
        	{
        	    TreeNode * node = que.front();
        		curLevel.push_back(node->val);
        		que.pop();
        		if(node->left)
        			que.push(node->left);
        		if(node->right)
        			que.push(node->right);
        	}
        }

        while(!treeStack.empty())
        {
        	ret.push_back(treeStack.top());
        	treeStack.pop();
        }
        return ret;
    }
};