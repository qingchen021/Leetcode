/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		if (root == NULL) return ret;
		vector<int> steps;
		stack<TreeNode*> treeStack1;
		stack<TreeNode*> treeStack2;
		treeStack1.push(root);
		while (!treeStack1.empty() || !treeStack2.empty())
		{
			if (!treeStack1.empty())
			{
				while (!treeStack1.empty())
				{
					TreeNode * top = treeStack1.top();
					treeStack1.pop();
					steps.push_back(top->val);
					if (top->left)
						treeStack2.push(top->left);
					if (top->right)
						treeStack2.push(top->right);
				}
				ret.push_back(steps);
				steps.clear();
			}

			if (!treeStack2.empty())
			{
				while (!treeStack2.empty())
				{
					TreeNode * top = treeStack2.top();
					treeStack2.pop();
					steps.push_back(top->val);
					if (top->right)
						treeStack1.push(top->right);
					if (top->left)
						treeStack1.push(top->left);
				}
				ret.push_back(steps);
				steps.clear();
			}
		}
		return ret;
	}
};
