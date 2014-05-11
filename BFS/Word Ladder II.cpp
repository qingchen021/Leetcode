/*
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.

*/

class Solution {

public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
	{
		vector<vector<string> > ret;
		unordered_map<string, vector<string> > childParents;
		unordered_set<string> visited;
		int len = start.length();
		queue<string> que;
		que.push(start);
		que.push("");
		visited.insert(start);
		childParents[start] = vector<string>();
		int minLevel = INT_MAX;
		int curLevel = 0;
		bool found = false;
		//有同一层遍历的时候，有可能出现同一个元素，这个时候需要记录这层每次遍历过的元素
		//保证后面元素遍历的，不能丢失另一个父亲
		// 例如 a- >c, b->c   [a,b,c];
		unordered_set<string> sameLevel;
		while (!que.empty())
		{
			string front = que.front();
			que.pop();

			if (front == "")
			{
				curLevel++;
				sameLevel.clear();
				if (!que.empty())
				{
					que.push("");
				}
			}
			else
			{
				if (minLevel < curLevel)
				{
					break;
				}
				if (front == end)
				{
					minLevel = curLevel;
					found = true;
				}
				for (int j = 0; j < len; j++)
				{
					for (int i = 0; i < 26; i++)
					{
						string tmp = front;
						tmp[j] = i + 'a';
						if (tmp != front)
						{
							if (dict.find(tmp) != dict.end())
							{
								if (tmp == end || visited.find(tmp) == visited.end() || sameLevel.find(tmp) != sameLevel.end())
								{
									//保证每层push的节点只push一次
									if (sameLevel.find(tmp) == sameLevel.end())
										que.push(tmp);
									childParents[tmp].push_back(front);
									visited.insert(tmp);
									sameLevel.insert(tmp);
								}
							}
						}
					}
				}
			}
		}
		if (found)
		{
			vector<string> steps;
			steps.push_back(end);
			//dfs 输出
			DFS(childParents, start, minLevel, end, steps, ret);
		}
		return ret;
	}

	void DFS(unordered_map<string, vector<string> > & stepMap, const string & start, const int minLevel, string cur, vector<string> & steps, vector<vector<string> > & res)
	{
		if (cur == start)
		{
			res.push_back(steps);
			return;
		}
		if (steps.size() >= minLevel + 1)
			return;
		vector<string> parents = stepMap[cur];
		for (int i = 0; i < parents.size(); i++)
		{
			steps.insert(steps.begin(), parents[i]);
			DFS(stepMap, start, minLevel, parents[i], steps, res);
			steps.erase(steps.begin());
		}
	}
};