/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int sRow = 0 , eRow = matrix.size()-1;
        if(eRow < 0)
            return ret;
        int sCol = 0, eCol = matrix[0].size()-1;
        while(sRow <= eRow && sCol <= eCol)
        {
        	for(int i = sCol ;i <= eCol ;i++ )
        		ret.push_back(matrix[sRow][i]);
        	for(int i = sRow +1 ;i <= eRow; i++)
        		ret.push_back(matrix[i][eCol]);
        	for(int i = eCol-1; i >= sCol ;i--)
        		//防止但重复添加
        		if(eRow >= sRow+1)
        			ret.push_back(matrix[eRow][i]);
        	for(int i = eRow-1 ; i > sRow;i--)
        		//防止但重复添加
        	    if(eCol >= sCol +1)
        	    	ret.push_back(matrix[i][sCol]);
        	sRow++;
        	eRow--;
        	sCol++;
        	eCol--;
        }
        return ret;
    }
};