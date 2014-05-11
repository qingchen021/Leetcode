/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > ret;
    	if(root == NULL) return ret;
        queue<TreeNode * > que;
        que.push(root);
        que.push(NULL);
        vector<int> level;
        while(!que.empty())
        {
        	if(que.front()== NULL)
        	{
        		que.pop();
        		ret.push_back(level);
        		level.clear();
        		if(!que.empty())
        		{
        			que.push(NULL);
        		}
        	}
        	else
        	{
        	    TreeNode * node = que.front();
        	    if(node->left)
        	        que.push(node->left);
        	    if(node->right)
        	        que.push(node->right);
        		level.push_back(node->val);
        		que.pop();
        	}
        }
        return ret;
    }
};