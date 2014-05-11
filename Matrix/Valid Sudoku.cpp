/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < 9; i++)
		{
			bool hashRow[10] = { 0 };
			bool hashCol[10] = { 0 };
			for (int j = 0; j <9; j++)
			{
				int numRow = board[i][j] -'0';
				int numCol = board[j][i]-'0';

				if (board[i][j] != '.')
				{
					if (hashRow[numRow])
						return false;
					else
						hashRow[numRow] = true;
				}

				if (board[j][i] != '.')
				{
					if (hashCol[numCol])
						return false;
					else
						hashCol[numCol] = true;
				}
			}
		}

		return isVaildGrid(board);
	}

	bool isVaildGrid(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 9; j += 3)
		{
			bool hash[10] = { 0 };
			for (int k = 0; k < 3; k++)
			for (int m = 0; m < 3; m++)
			{
				int row = i + k;
				int col = j + m;
				if (board[row][col] == '.')
					continue;				
				int num = board[row][col]-'0';
				if (hash[num])
				{
					return false;
				}
				else
				{
					hash[num] = true;
				}
			}
		}
		return true;
	}
};