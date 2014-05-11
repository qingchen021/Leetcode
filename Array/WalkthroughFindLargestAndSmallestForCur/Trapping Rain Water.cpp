/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!
*/

class Solution {
public:
	//这个题目主要看当前高度，能被其出本身之外的左边，右边高度的最小值减去之后还剩下的高度，就是这个高度能容下的高度
	//要整体来看这个题目，注意最左边和最右边 都不能容水的
    int trap(int A[], int n) {
	vector<int> leftBiggest(n,-1);
	vector<int> rightBiggest(n,-1);
	int biggest = A[0];
    for(int i = 1 ; i < n;i++)
	{
		leftBiggest[i] = biggest;
		if(A[i] > biggest)
		{
			biggest = A[i];
		}
	}
	biggest = A[n-1];
	for(int i = n-2 ; i >= 0 ;--i)
	{
		rightBiggest[i] = biggest;
		if(A[i] > biggest)
		{
			biggest = A[i];
		}
	}
	int ret = 0;
	for(int i = 1 ;i <= n-2;i++)
	{
		int h = min(leftBiggest[i] , rightBiggest[i]) - A[i];
		if(h > 0)
		{
			ret += h;
		}
	}
	return ret;
    }
};