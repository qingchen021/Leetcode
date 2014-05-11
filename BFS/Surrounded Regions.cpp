/*
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

class Solution {
	struct Pos
	{
		int row, col;
		Pos(int i, int j) :row(i), col(j)
		{

		}
	};
public:
	void solve(vector<vector<char>> &board)
	{
		if (board.size() == 0)
			return;
		vector<bool> tmp(board[0].size(), false);
		vector<vector<bool> > visitedMap(board.size(), tmp);
		for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 'O' && visitedMap[i][j] == false)
			{
				vector<Pos> steps;
				bool ret = false;
				solve(i, j, board, steps, visitedMap, ret);
				if (!ret)
				{
					for (int k = 0; k < steps.size(); k++)
					{
						board[steps[k].row][steps[k].col] = 'X';
					}
				}
			}
		}
	}

	void solve(int i, int j, vector<vector<char>> &board, vector<Pos> & steps, vector<vector<bool> > & visitedMap, bool & res)
	{
		int rows = board.size() - 1;
		int cols = board[0].size() - 1;
		queue<Pos> que;
		que.push(Pos(i, j));
		visitedMap[i][j] = true;
		while (!que.empty())
		{
			Pos front = que.front();
			que.pop();			
			i = front.row;
			j = front.col;
			if (board[front.row][front.col] == 'O')
			{
				steps.push_back(front);
			}
			if (front.row == 0 || front.row == rows || front.col == 0 || front.col == cols)
			{
				res = true;
			}
			for (int k = -1; k < 2; k++)
			for (int m = -1; m < 2; m++)
			{
				if ((k != 0 && m != 0) || (k == 0 && m == 0))
					continue;
				if (i + k < 0 || i + k > rows || j + m < 0 || j + m > cols || visitedMap[i + k][j + m] || board[i + k][j + m] == 'X')
					continue;

				que.push(Pos(i + k, j + m));
				visitedMap[i + k][j + m] = true;
			}
		}
		return;
	}
};