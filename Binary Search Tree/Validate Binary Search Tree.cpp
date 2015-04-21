/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

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
    bool isValidBST(TreeNode *root) {
        TreeNode * pre = NULL;
        return isVaildBST(pre,root);
    }
    bool isVaildBST(TreeNode * & pre, TreeNode * root)
    {
        if(!root)
            return true;
        if(!isVaildBST(pre,root->left))
            return false;
        if(pre!=NULL)
        {
            if(pre->val>=root->val)
                return false;
        }
        pre = root;
        return isVaildBST(pre,root->right);
    }
};

//another solution
/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(!root)
            return true;
        int smallest = INT_MAX, biggest = INT_MIN;
       return isVaildBST(root,smallest,biggest);
    }
    bool isVaildBST(TreeNode * root, int & smallest, int & biggest)
    {
            if(root->left)
                if(!isVaildBST(root->left,smallest,biggest))
                    return false;
            int cur = root->val;
            if(cur <= biggest)
                return false;
            if(biggest < root->val)
                biggest = root->val;
            if(smallest > root->val)
                smallest = root->val;
             if(root->right)
                if(!isVaildBST(root->right,smallest,biggest))
                    return false;
             if(cur < smallest)
                return false;
            return true;
    }
};
*/