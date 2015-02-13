/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
	int maximumGap(vector<int> &num) {
		if (num.size()<2)
			return 0;
		int minNum = INT_MAX, maxNum = INT_MIN;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] < minNum)
				minNum = num[i];
			if (num[i] > maxNum)
				maxNum = num[i];
		}
		double d = (double)(maxNum - minNum) / (num.size() - 1);
		vector<pair<int, int> > intervals(num.size() - 1, pair<int, int>(-1, -1));
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == minNum || num[i] == maxNum)
				continue;
			int t = num[i];
			int k = (num[i] - minNum) / d;
			if (intervals[k].first == -1 || intervals[k].first > num[i])
				intervals[k].first = num[i];
			if (intervals[k].second == -1 || intervals[k].second < num[i])
				intervals[k].second = num[i];
		}
		intervals.insert(intervals.begin(), pair<int, int>(minNum, minNum));
		intervals.push_back(pair<int, int>(maxNum, maxNum));
		int curMax = 0;
		int pre = minNum;
		for (int i = 0; i < intervals.size(); i++)
		{
			int m = 0;
			if (intervals[i].first != -1)
			{
				 m = intervals[i].first - pre;
				if (m>curMax)
					curMax = m;
				pre = intervals[i].first;
			}
			if (intervals[i].second != -1)
			{
				m = intervals[i].second - pre;
				if (m > curMax)
					curMax = m;
				pre = intervals[i].second;
			}
		}
		return curMax;
	}
};