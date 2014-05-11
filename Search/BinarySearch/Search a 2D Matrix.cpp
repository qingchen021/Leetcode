/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		bool found = false;
		int row = 0;
		if (FindRow(matrix, target, row))
			return true;
		found = FindCol(matrix, target, row);
		return found;
	}

	bool FindRow(const vector<vector<int> > & matrix, int target ,int & row)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		int begin = 0, end = rows - 1;
		//最接近target且比它大的index
		int lastBig ;
		while (begin <= end)
		{
			lastBig = (begin + end) / 2;
			int mid = matrix[lastBig][cols - 1];
			if (mid == target)
			{
				return true;
			}
			else if (mid > target)
			{
				end--;
			}
			else
				begin++;
		}
		row = lastBig;
		return false;
	}

	bool FindCol(const vector<vector<int> > & matrix, int target, int row)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		int begin = 0, end = cols - 1;
		while (begin <= end)
		{
			int mid = matrix[row][(begin + end) / 2];
			if (mid == target)
			{
				return true;
			}
			else if (mid > target)
			{
				end--;
			}
			else
				begin++;
		}
		return false;
	}
};