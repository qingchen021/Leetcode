/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, unordered_set<int>> courses;
		for (int i = 0; i<numCourses; i++)
		{
			courses[i] = unordered_set<int>();
		}
		for (int i = 0; i < prerequisites.size(); i++)
		{
			auto p = prerequisites[i];
			if (p[0] != p[1])
				courses[p[0]].insert(p[1]);
		}
		while (courses.size()>0)
		{
			int noDep = -1;
			for (auto i = courses.begin(); i != courses.end(); i++)
			{
				if (i->second.size() == 0)
				{
					noDep = i->first;
					courses.erase(i);
					break;
				}
			}
			if (noDep == -1)
			{
				return false;
			}
			for (auto i = courses.begin(); i != courses.end(); i++)
			{
				if (i->second.find(noDep) != i->second.end())
				{
					i->second.erase(noDep);
				}
			}
		}
		return true;
	}
};