/*
 Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/

class Solution {
	class Trie
	{
	public:
		Trie()
		{
			IsEnd = false;
			for (int i = 0; i<27; i++)
				Children[i] = NULL;
		}
		void Insert(string s)
		{
			Trie *p = this;
			for (int i = 0; i < s.length(); i++)
			{
				if (p->Children[s[i] - 'a'] == NULL)
				{
					p->Children[s[i] - 'a'] = new Trie();
				}
				p = p->Children[s[i] - 'a'];
			}
			p->IsEnd = true;
		}

		Trie* Children[27];
		bool IsEnd;
	};
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
	    vector<string> rets;
		int rows = board.size();
		if (rows == 0)
			return rets;
		int cols = cols = board[0].size();
		Trie * root = new Trie();
		for (int i = 0; i<words.size(); i++)
		{
			root->Insert(words[i]);
		}
		vector<vector<bool>>  visitedMap(rows, vector<bool>(cols, false));
		for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
		{
			if (root->Children[board[i][j] - 'a'] != NULL)
			{
				string step;
				step.push_back(board[i][j]);
				findWords(board, i, j, visitedMap, root->Children[board[i][j] - 'a'], step, rets);
			}
		}
		return rets;
	}
	void findWords(vector<vector<char>>& board, int row, int col, vector<vector<bool>> & visitedMap, Trie * tree, string step, vector<string>& ret)
	{
		int rows = board.size(), cols = board[0].size();
		if (tree->IsEnd)
		{
			ret.push_back(step);
			tree->IsEnd = false;
		}
		visitedMap[row][col] = true;
		int a[] = { -1, 1, 0, 0 };
		int b[] = { 0, 0, -1, 1 };
		for (int i = 0; i<4; i++)
		{
			int nextRow = row + a[i], nextCol = col + b[i];
			if (nextRow < 0 
				|| nextRow >= rows 
				|| nextCol < 0 
				|| nextCol >= cols 
				|| visitedMap[nextRow][nextCol] 
				|| tree->Children[board[nextRow][nextCol] - 'a'] == NULL)
			{
				continue;
			}
			string ss = step;
			ss.append(1, board[nextRow][nextCol]);
			findWords(board, nextRow, nextCol, visitedMap, tree->Children[board[nextRow][nextCol] - 'a'], ss, ret);
		}
		visitedMap[row][col] = false;
	}
};