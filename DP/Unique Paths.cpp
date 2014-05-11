/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101]={0};
        for(int i = 0 ;i < m ;i++)
        	for(int j = 0 ; j < n;j++)
        	{
        		if(i ==0 && j == 0)
        		{
        			dp[i][j] = 1;
        		}
        		else
        		{
        			int left = 0, top = 0;
        			if(j-1 >= 0)
        				left = dp[i][j-1];
        			if(i-1 >= 0)
        				top = dp[i-1][j];
        			dp[i][j]=left + top;
        		}
        	}
        return dp[m-1][n-1];
    }
};