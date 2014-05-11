/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }

    vector<TreeNode *> generateTrees(int begin , int end) {
    	vector<TreeNode *> ret;
        if(begin > end )
        {
        	ret.push_back(NULL);
        	return ret;
        }
        if(begin == end)
        {
        	ret.push_back(new TreeNode(begin));
        	return ret;
        }
        for(int k = begin ;k <= end ;k++)
        {        	
        	vector<TreeNode *> left = generateTrees(begin,k-1);
        	vector<TreeNode *> right = generateTrees(k+1,end);
        	for(int i = 0 ;i < left.size() ;i++)
        		for(int j = 0 ; j < right.size() ; j++)
        		{
        			TreeNode * cur = new TreeNode(k);
        			cur->left = left[i];
        			cur->right = right[j];
        			ret.push_back(cur);
        		}
        }
        return ret;
    }
};