/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() == 0)
			return 0;
		int maxNum = 1;
		unordered_map<float, int> mp;
		//核心思想就是对每个点与其他的点比较，如果其它的点与这个点同一条直线，那么斜率都是一样的，
		//值得注意的事项是这里面有重复点的时候，base要加上1
		for (int i = 0; i < points.size(); i++)
		{
			mp.clear();
			int base = 1;
			for (int j = 0; j < points.size(); j++)
			{
				if (i == j)
					continue;
				//重复的点的时候，base要加一，而且maxNum要随着变化
				else if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					++base;
					maxNum = max(base, maxNum);
				}
				else
				{
					float slop;
					if (points[i].x == points[j].x)
						slop = INT_MAX;
					else
						//特别注意这个地方的要用float取精度
						slop = (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
					if (mp.find(slop) != mp.end())
					{
						++mp[slop];
					}
					else
					{
						mp[slop] = base + 1;
					}
					maxNum = max(mp[slop], maxNum);
				}
			}
		}
		return maxNum;
	}
};