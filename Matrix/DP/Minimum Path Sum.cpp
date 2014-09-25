/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if(grid.size() == 0)
            return 0;
        vector<int> dp(grid[0].size(),0);
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0 ;i < rows;i++)
            for(int j = 0; j < cols;j++)
            {
                int left = INT_MAX, top = INT_MAX;
                if(j>0)
                    left = dp[j-1];
                if(i>0)
                    top = dp[j];
                if(i==0 &&j==0)
                    dp[j] = grid[i][j];
                else
                    dp[j] = min(left,top) + grid[i][j];
            }
        return dp[cols-1];
    }
};
