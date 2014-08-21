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
        if(root==NULL)
            return ;
        Flatten(root);
    }
    
    TreeNode * Flatten(TreeNode * root)
    {
        TreeNode *left = NULL,*right = NULL;
        if(root->left)
            left = Flatten(root->left);
        if(root->right)
            right = Flatten(root->right);
        if(left)
            left->right = root->right;
        root->right = (root->left==NULL?root->right:root->left);
        root->left = NULL;
        if(right != NULL)
        {
            return right;
        }
        else if(left != NULL)
        {
            return left;
        }
        else
            return root;
    }
};