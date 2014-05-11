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
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > ret;
		if (numRows == 0) return ret;
		ret.push_back(vector<int>(1, 1));
		for (int i = 1; i < numRows; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
				{
					vec.push_back(1);
				}
				else
				{
					vec.push_back(ret[i - 1][j-1] + ret[i - 1][j ]);
				}
			}
			ret.push_back(vec);
		}
		return ret;
	}
};