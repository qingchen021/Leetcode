/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode *root) {
        Flatten(root);
    }

    TreeNode* Flatten(TreeNode * root)
    {
    	if(root == NULL)
    		return NULL;
    	TreeNode * left = Flatten(root->left);
    	TreeNode * mostRight = left;
    	while(mostRight && mostRight->right)
    		mostRight = mostRight->right;
    	root->left = NULL;
    	if(mostRight!=NULL)
    	{
    		mostRight->right = root->right;
    		root->right = left;
    	}
    	Flatten(root->right);
    	return root;
    }
};