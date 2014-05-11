/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
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
	vector<int> inOrder;
	vector<int> postOrder;
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int size = inorder.size();
		if (size == 0)
			return NULL;
		inOrder = inorder;
		postOrder = postorder;
		return buildTree(0, size - 1, 0, size - 1);
	}

	TreeNode *buildTree(int inStart, int inEnd, int postStart, int postEnd)
	{
		if (postStart > postEnd)
			return NULL;
		TreeNode * root = new TreeNode(postOrder[postEnd]);

		int inPos;
		for (int i = inStart; i <= inEnd; i++)
		{
			if (inOrder[i] == postOrder[postEnd])
			{
				inPos = i;
				break;
			}
		}

		int leftCounts = inPos - inStart;
		int rightCounts = inEnd - inPos;
		TreeNode * left = buildTree(inStart, inPos - 1, postStart, postStart + leftCounts - 1);
		TreeNode * right = buildTree(inPos + 1, inEnd, postEnd - rightCounts, postEnd - 1);
		root->left = left;
		root->right = right;
		return root;

	}
};