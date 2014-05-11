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
	string simplifyPath(string path) {
		stack<string> pathStack;
		int pre = 0, cur = 0;
		while (cur < path.length() - 1 && pre < path.length() - 1)
		{
			cur = path.find('/', pre + 1);
			if (cur == string::npos)
				cur = path.length();
			string str = path.substr(pre + 1, cur - pre - 1);
			pre = cur;
			if (str == "." || str == "")
			{
				continue;
			}
			else if (str == "..")
			{
				if (!pathStack.empty())
					pathStack.pop();
			}
			else
				pathStack.push(str);
		}
		string ret = "";
		while (!pathStack.empty())
		{
			ret.insert(0, "/" + pathStack.top());
			pathStack.pop();
		}

		if (ret == "")
			return "/";
		else
			return ret;
	}
};
