/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num,0,num.size()-1);
    }

    TreeNode *sortedArrayToBST(vector<int> &num, int begin, int end) 
    {
    	if(begin > end) 
    		return NULL;
    	int mid = (begin + end)/2;
    	TreeNode * node = new TreeNode(num[mid]);
    	TreeNode * left = sortedArrayToBST(num, begin, mid -1);
    	TreeNode * right = sortedArrayToBST(num,mid+1, end);
    	node->left = left;
    	node->right = right;
    	return node;
    }

};