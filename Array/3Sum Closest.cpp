/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int dic = -10000000;
		int ret = num[0] + num[1] + num[2];
		for (int i = 0; i < num.size(); i++)
		{
				int begin = i + 1;
				int end = num.size() - 1;
				while (begin < end)
				{
					if (num[begin] + num[end] + num[i] == target)
					{
						return target;
					}
					int cur = num[i] + num[begin] + num[end] - target;
					int c1 = cur>0 ? cur : -cur;
					int c2 = dic>0 ? dic : -dic;
					if (c1 < c2)
					{
						dic = cur;
						ret = num[i] + num[begin] + num[end];
					}
					if (num[begin] + num[end] + num[i] > target)
					{
						--end;
					}
					else
					{
						++begin;
					}
				}
			}
		return ret;
	}
};