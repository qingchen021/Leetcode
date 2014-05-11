/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    //从数组两边遍历，算每个位置最大值减去它之前最小值，得到左边的最大值
    //后面最大值减去它后面最小值的得到的最大值
	int maxProfit(vector<int> &prices) {
		int first = 0, second = 0;
		int len = prices.size();
		if (len == 0) return 0;
		vector<int> leftMax(len, 0);
		vector<int> rightMax(len, 0);

		int small = prices[0];
		int curMax = 0;
		for (int i = 1; i < len; i++)
		{
		    //这个从当前值减去直到当前值最小值得到的最大值
			curMax = max(curMax, prices[i] - small);
			//注意每个位置都要有
			leftMax[i] = curMax;
			if (prices[i] < small)
			{
				small = prices[i];
				leftMax[i] = curMax;
			}
		}

		int big = prices[len - 1];
		curMax = 0;
		for (int i = len - 2; i >= 0; i--)
		{
		    //这个从后面算最大值减去当前值，所得的最大值
			curMax = max(curMax, big - prices[i]);
			//注意每个位置都要有
			rightMax[i] = curMax;
			if (prices[i] > big)
			{
				big = prices[i];
			}
		}

		int ret = 0;
		for (int i = 0; i < len; i++)
		{
			ret = max(leftMax[i] + rightMax[i], ret);
		}

		return ret;
	}
};