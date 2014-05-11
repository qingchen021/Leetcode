/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int DP[1000][1000];
		int rows = grid.size();
		int cols = grid[0].size();
		//自顶向下，每个数，要么从左边来，要么从上边来，一次遍历所有的矩阵，
		//非常基础的DP的题目
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				int left = INT_MAX, top = INT_MAX;
				if (i > 0)
					top = DP[i - 1][j];
				if (j >0)
					left = DP[i][j - 1];
				if (i == 0 && j == 0)
					DP[0][0] = grid[0][0];
				else
					DP[i][j] = min(left, top) + grid[i][j];
			}
		return DP[rows - 1][cols - 1];
	}
};