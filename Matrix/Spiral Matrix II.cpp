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
    	vector<int> tmp(n,0);
    	vector<vector<int> > ret(n,tmp);
        int sRow = 0, eRow = n-1;
        int sCol = 0 ,eCol = n-1;
        int cur= 0;
        while(sRow <= eRow)
        {
        	for(int i = sCol ; i <= eCol;i++ )
        	{
        		ret[sRow][i] = ++cur;
        	}
        	for(int i = sRow+1 ; i <= eRow ;i++)
        	{
        		ret[i][eCol] = ++cur;
        	}
        	for(int i = eCol-1;i >= sCol ; i--)
        	{
        		ret[eRow][i] = ++cur;
        	}
        	for(int i = eRow-1;i> sRow;i--)
        	{
        		ret[i][sCol] = ++cur;
        	}
        	sRow++;
        	eRow--;
        	sCol++;
        	eCol--;
        }
        return ret;
    }
};