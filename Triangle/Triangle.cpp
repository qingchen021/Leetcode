/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
*/

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0) return 0;
		if (triangle.size() == 1) return triangle[0][0];
		int maxLen = triangle[triangle.size() - 1].size();
		vector<vector<int> > mem(2, vector<int>(maxLen,INT_MAX));
		
		//用两个循环数组来表示之前每行的最小值
		mem[0][0] = triangle[0][0];

		int pre = -1, now = 0;
		for (int i = 1; i < triangle.size(); i++)
		{
			//放在这里表示退出的时候 最后使用的是now，不是pre。
			pre = now;
			now = (now + 1) % 2;
			for (int j = 0; j <= i; j++)
			{
				int first = INT_MAX, second = INT_MAX;
				if (j - 1 >= 0)
					first = mem[pre][j - 1];
				if (j < i)
					second = mem[pre][j];
				mem[now][j] = min(first, second) + triangle[i][j];
			}
		}
		int ret = INT_MAX;
		for (int i = 0; i < maxLen; i++)
		{
			ret = min(ret, mem[now][i]);
		}
		return ret;
	}
};