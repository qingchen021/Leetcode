/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

A sudoku puzzle...
http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png

...and its solution numbers marked in red. 
*/

class Solution
{
public:
	void solveSudoku(vector<vector<char> > &board) {
		SolveSudoku(board, 0, 0);
		return;
	}

	bool isVaild(const vector<vector<char> > & board, int row, int col, char fill)
	{
		int c = fill - '0';
		bool hash[10] = { 0 };
		hash[c] = true;
		for (int i = 0; i < 9; i++)
		{
			char colChar = board[i][col];
			char rowChar = board[row][i];
			if (colChar != '.')
			{
				int nCol = board[i][col] - '0';
				if (hash[nCol])
					return false;
			}

			if (rowChar != '.')
			{
				int nRow = board[row][i] - '0';
				if (hash[nRow])
					return false;
			}
		}

		int startRow = row / 3 * 3;
		int startCol = col / 3 * 3;

		for (int k = 0; k < 3; k++)
		for (int m = 0; m < 3; m++)
		{
			int row = startRow + m;
			int col = startCol + k;
			if (board[row][col] != '.')
			{
				int num = board[row][col] - '0';
				if (hash[num])
					return false;
			}
		}

		return true;
	}

	bool SolveSudoku(vector<vector<char> > &board, int row, int col)
	{
		int rows = board.size();
		int cols = board[0].size();
		if (row < 0 || row >= rows || col < 0 || col >= cols)
			return  false;

		if (board[row][col] != '.')
		{
			if (!GetNextPoint(board, row, col))
			{
				return true;
			}
		}

		for (int i = 1; i <= 9; i++)
		{
			char curValue = '0' + i;
			if (isVaild(board, row, col, curValue))
			{
				board[row][col] = curValue;
				int nextRow = row;
				int nextCol = col;
				if (!GetNextPoint(board, nextRow, nextCol))
				{
					return true;
				}
				if (SolveSudoku(board, nextRow, nextCol))
					return true;
			}
		}
		board[row][col] = '.';
		return false;
	}

	bool GetNextPoint(const vector<vector<char> > &board, int & row, int & col)
	{
		int rows = board.size();
		int cols = board[0].size();
		do{
			if (col == cols - 1)
			{
				row += 1;
				col = 0;
			}
			else
				col += 1;
			if (row >= rows)
				return false;
		} while (board[row][col] != '.');
		return true;
	}
};