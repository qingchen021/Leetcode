/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
	string simplifyPath(string path)
	{
		stack<string> paths;
		int last = 0;
		int cur = 1;
		while (cur <= path.size())
		{
			if (cur == path.size() || path[cur] == '/')
			{
				if (cur - last > 1)
				{
					string str = path.substr(last + 1, cur - last - 1);
					last = cur;
					if (str == "..")
					{
						if (!paths.empty())
							paths.pop();
					}
					else if (str != ".")
					{
						paths.push(str);
					}
				}
				else
				{
					last = cur;
				}
			}
			++cur;
		}
		string ret = "";
		while (!paths.empty())
		{
			ret.insert(0, "/" + paths.top());
			paths.pop();
		}
		return ret.length() == 0 ? "/" : ret;
	}
};
