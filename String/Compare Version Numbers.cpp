/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution {
public:
	int compareVersion(string version1, string version2)
	{
		string str1, str2;
		for (;version1 != version2;)
		{
			str1 = NextStr(version1);
			str2 = NextStr(version2);
			int i = stoi(str1), j = stoi(str2);
			if (i != j)
				return i>j ? 1 : -1;
		}
		return 0;
	}

	string NextStr(string &str)
	{
		if (str.length() == 0)
			return "0";

		string ret = str;
		for (int i = 0; i< str.length(); i++)
		{
			if (str[i] == '.')
			{
				string ret = str.substr(0, i);
				str = str.substr(i + 1);
				return ret;
			}
		}
		str = "";
		return ret;
	}
};