/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
class Solution {
public:
	int numTrees(int n) {
		return numTrees(1, n);
	}

	int numTrees(int begin, int end)
	{
	     //假如beign < end 或者 begin > end 都视为只有一种排列
		if (begin > end) return 1;
		if (begin == end) return 1;
		int ret = 0;
		for (int i = begin; i <= end; i++)
		{
			int left = numTrees(begin, i - 1);
			int right = numTrees(i + 1, end);
			//此处是乘积不是和
			ret += left * right;
		}
		return ret;
	}
};