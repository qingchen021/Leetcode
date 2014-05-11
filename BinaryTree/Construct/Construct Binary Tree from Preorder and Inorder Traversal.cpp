/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/

class Solution {
	vector<int> preOrder;
	vector<int> inOrder;
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int size = preorder.size();
		if (size == 0)
			return NULL;
		preOrder = preorder;
		inOrder = inorder;
		return buildTree(0, size - 1, 0, size - 1);
	}

	TreeNode *buildTree(int inStart, int inEnd, int preStart, int preEnd)
	{
		if (preStart > preEnd)
			return NULL;
		TreeNode * root = new TreeNode(preOrder[preStart]);

		int inPos;
		for (int i = inStart; i <= inEnd; i++)
		{
			if (inOrder[i] == preOrder[preStart])
			{
				inPos = i;
				break;
			}
		}
		int leftCounts = inPos - inStart;
		int rightCounts = inEnd - inPos;
		TreeNode * left = buildTree(inStart, inPos - 1, preStart + 1, preStart + leftCounts);
		TreeNode * right = buildTree(inPos + 1, inEnd, preEnd - rightCounts + 1, preEnd);
		root->left = left;
		root->right = right;
		return root;

	}
};