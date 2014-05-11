/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
*/

class Solution {
public:
	int jump(int A[], int n) {
		if (n == 0 || n == 1) return 0;
		int end = 0;
		int level = 0;
		//表示这一层最大能达到的index
		int last = 0;
		for (int i = 0; i <= end; i++)
		{
			//如果超过这一次最大能达到的index，那么level就要增加1
			if (i > last)
			{
				level++;
				//更新level的时候要更新这一层能达到的最大index
				last = end;
			}
			//每个元素都要去更新这一层能达到的最大的index
			end = max(end, A[i] + i);
			//如果当前end大于n-1,代表已经达到最后一个，返回当前level+1
			if (end >= n - 1)
			{
				return level + 1;
			}
		}
	}
};