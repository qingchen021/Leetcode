/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int dp[100][100] ={0};
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1) return 0;
        for(int i = 0 ;i < rows; i++)
        	for(int j = 0 ; j < cols; j++)
        	{
        		if(i == 0 && j == 0)
        		{
        			dp[i][j] =1;
        		}
        		else
        		{
        			if(obstacleGrid[i][j] == 1)
        			{
        				dp[i][j]=0;
        			}
        			else
        			{
        				int left = 0, top =0;
        				if(i-1>= 0)
        					top = dp[i-1][j];
        				if(j-1>=0)
        					left = dp[i][j-1];
        				dp[i][j]= left + top;
        			}
        		}
        	}
        return dp[rows-1][cols-1];
    }
};