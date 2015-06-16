/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        vector<vector<int> > dp(rows,vector<int>(cols,0));
        int ret = 0;
        for(int i = 0;i<rows;i++)
            for(int j = 0;j<cols;j++)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    int left = 0, top = 0, leftTop = 0;
                    if(i>0)
                        top = dp[i-1][j];
                    if(j>0)
                        left = dp[i][j-1];
                    if(i>0&&j>0)
                        leftTop = dp[i-1][j-1];
                    dp[i][j] = min(min(top,left),leftTop) + 1;
                    if(dp[i][j]>ret)
                        ret = dp[i][j];
                }
            }
        return ret*ret;
    }
};