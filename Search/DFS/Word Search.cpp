/*
 Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

 class Solution {
	 bool visitedMap[1000][1000];
 public:
	 bool exist(vector<vector<char> > &board, string word) {
		 bool ans = false;
		 memset(visitedMap, 0, sizeof(visitedMap));
		 for (int i = 0; i < board.size(); i++)
			 for (int j = 0; j < board[0].size(); j++)
			 {
				 if (board[i][j] == word[0])
				 {
					 ans = Exist(i, j, board, word.substr(1));
					 if (ans)
						 return true;
				 }
			 }
		 return false;
	 }

	 bool Exist(int i, int j, vector<vector<char> > &board, string word)
	 {
		 if (0 == word.length())
		 {
			 return true;
		 }
		 else
		 {
			 visitedMap[i][j] = true;
			 for (int k = -1; k < 2; k += 1)
				 for (int m = -1; m < 2; m += 1)
				 {
					 if (k != 0 && m != 0)
						 continue;
					 if (CanMove(i + k, j + m, board.size(), board[0].size()))
					 {
						 if (board[i + k][j + m] == word[0])
						 {
							 if (Exist(i + k, j + m, board, word.substr(1)))
								 return true;
						 }
					 }
				 }
			 visitedMap[i][j] = false;
			 return false;
		 }
	 }

	 bool CanMove(int row, int col, const int rows, const int cols)
	 {
		 return row>-1 && row < rows && col >-1 && col < cols && visitedMap[row][col] == false;
	 }
 };