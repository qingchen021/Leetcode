/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //Divide and conquer
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        TreeNode * left = root->left, *right = root->right;
        int total = 2;
        while(left && right)
        {
            total *= 2;
            left = left->left;
            right = right->right;
        }
        if(left == NULL && right == NULL)
        {
             return total -1;
        }
        else
        {
           return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};