/*
http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		vector<int> steps;
		solveNQueens(n, steps, res);
		return res;
	}

	void solveNQueens(const int n, vector<int> & steps, vector<vector<string> > & res)
	{
		if (steps.size() == n)
		{
			vector<string> v;
			for (int i = 0; i < n; i++)
			{
				string tmp(n, '.');
				tmp[steps[i]] = 'Q';
				v.push_back(tmp);
			}
			res.push_back(v);
			return;
		}
		else
		{
			int row = steps.size();
			for (int i = 0; i < n; i++)
			{
				//每走一步，都要看下当前step是否vaild
				if (vaild(row, i, steps))
				{
					//对当前row的每个col进行遍历
					steps.push_back(i);
					solveNQueens(n, steps, res);
					steps.pop_back();
				}
			}
		}
	}

	bool vaild(int row, int col, const vector<int> & path)
	{
		for (int i = 0; i < path.size(); i++)
		{
		    //注意斜对角45 或者 45 度
			if (path[i] == col || path[i] - col == i - row || path[i] - col == row - i)
				return false;
		}
		return true;
	}
};