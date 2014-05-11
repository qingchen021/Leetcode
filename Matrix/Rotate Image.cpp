/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int sRow = 0, eRow = matrix.size()-1;
        int sCol = 0, eCol = matrix[0].size()-1;
        //画个图，相当于顺时针的一个连续交换的过程，注意中间距离用相对距离表示
        //最后一列sRow至eRow-1与第sRow的sCol至eCol-1交换
        //最后一行eCol至sCol-1与sRows的sCol至eCol-1交换
        //第一列的eCol至sCol-1与sRows的sCol至eCol-1交换
        while(sRow <= eRow)
        {
        	for(int i = sCol;i < eCol ;i++)
        	{
        		swap(matrix[sRow][i],matrix[i-sCol+sRow][eCol]);
        	}
        	for(int i = eCol ; i>sCol;i--)
        	{
        		swap(matrix[eRow][i],matrix[sRow][eCol-i+sCol]);
        	}
        	for(int i = eRow ; i > sRow ;i--)
        	{
        		swap(matrix[i][sCol],matrix[sRow][sCol + eRow - i]);
        	}
        	sRow++;
        	eRow--;
        	sCol++;
        	eCol--;
        }
    }
};