/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * cur = root;
        while(cur)
        {
            TreeLinkNode * thisLevel = cur;
            TreeLinkNode * nextLevel = NULL;
            TreeLinkNode dummyNode(0);
            TreeLinkNode * nextPre = &dummyNode;
            while(thisLevel)
            {
                if(thisLevel->left)
                {
                    nextPre->next = thisLevel->left;
                    nextPre = nextPre->next;
                    if(!nextLevel)
                        nextLevel = thisLevel->left;
                }
                if(thisLevel->right)
                {
                    nextPre->next = thisLevel->right;
                    nextPre = nextPre->next;
                    if(!nextLevel)
                        nextLevel = thisLevel->right;
                }
                thisLevel = thisLevel->next;
            }
            cur = nextLevel;
        }
    }
};
