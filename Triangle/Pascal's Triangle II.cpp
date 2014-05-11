/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/

 class Solution {
 public:
	 vector<int> getRow(int rowIndex) {
		 vector<int> tmp(rowIndex+1, 1);
		 vector<vector<int> > rows(2, tmp);
		 int cur = 0;
		 int pre = -1;
		 for (int i = 1; i <= rowIndex; i++)
		 {
		     pre = cur;
		     cur = (cur + 1) % 2;
			 for (int j = 0; j <= i; j++)
			 {
				 if (j == 0 || j == i)
					 rows[cur][j] = 1;
				 else
					 rows[cur][j] = rows[pre][j - 1] + rows[pre][j];
			 }
		 }
		 return rows[cur];
	 }
 };