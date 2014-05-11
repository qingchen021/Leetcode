/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
       	set<int> cols;
        for(int i = 0 ; i< matrix.size();i++)
        {
        	bool hasZero = false;
        	for(int j = 0 ; j < matrix[0].size();j++ )
        	{
        		if(matrix[i][j]==0)
        		{
        			cols.insert(j);
        			hasZero = true;
        		}
        	}
        	if(hasZero)
        	{
        		for(int j = 0 ; j < matrix[0].size();j++ )
        		{
        			matrix[i][j] = 0;
        		}
        	}
        }
        for(set<int>::iterator begin = cols.begin();begin != cols.end();++begin )
        {
        	for(int i = 0 ;i < matrix.size();i++)
        	{
        		matrix[i][*begin]=0;
        	}
        }
    }
};