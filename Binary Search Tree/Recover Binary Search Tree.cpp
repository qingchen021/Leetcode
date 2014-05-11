/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    void recoverTree(TreeNode *root) {
        TreeNode * first = NULL, * second = NULL , * pre = NULL;
        recoverTree(root,pre,first,second);
        swap(first->val,second->val);
    }
    void recoverTree(TreeNode *cur, TreeNode * & pre,TreeNode * & first, TreeNode * & second)
    {
        if(cur->left)
            recoverTree(cur->left, pre, first, second);
        if(pre != NULL)
        {
            if(pre->val > cur->val)
            {
                if(first==NULL)
                {
                    first = pre;
                }
                second = cur;
            }
        }
        pre = cur;
        if(cur->right)
            recoverTree(cur->right, pre, first, second);
    }
};