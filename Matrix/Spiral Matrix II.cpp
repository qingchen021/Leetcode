/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        if(n==0)
            return matrix;
        int sRow = 0, eRow = matrix.size()-1;
        int sCol = 0, eCol = matrix[0].size()-1;
       int cur = 0;
       while(true)
       {
        for(int i = sCol ;i<= eCol;i++)
           matrix[sRow][i] = ++cur;
        sRow++;
        if(sRow>eRow)
            break;
        for(int i = sRow ;i<= eRow;i++)
            matrix[i][eCol]=++cur;
        eCol--;
        if(sCol>eCol)
            break;
        for(int i = eCol;i>=sCol;i--)
             matrix[eRow][i]= ++cur;
        eRow--;
        if(sRow>eRow)
            break;
        for(int i = eRow;i>=sRow;i--)
             matrix[i][sCol]=++cur;
        sCol++;
        if(sCol>eCol)
            break;
       }
        return matrix;
    }
};