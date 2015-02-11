/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		vector<string> res;
		if (s.length() < 10)
			return res;
		unordered_map<int, int> hash;
		for (int i = 0; i <= s.length() - 10; i++)
		{
			string sb = s.substr(i, 10);
			int c = StringToInt(sb);
			if (hash.find(c) == hash.end())
			{
				hash[c]++;
			}
			else
			{
				hash[c]++;
				if (hash[c] < 3)
				{
					res.push_back(s.substr(i, 10));
				}
			}
		}
		return res;
	}
	int StringToInt(string s)
	{
		int res = 0;
		int i = 0;
		for (char c : s)
		{
			int n = 0;
			switch (c)
			{
			case 'A':
				n = 0;
				break;
			case 'C':
				n = 1;
				break;
			case 'G':
				n = 2;
				break;
			case 'T':
				n = 3;
				break;
			default:
				break;
			}
			res += n << i;
			i += 2;
		}
		return res;
	}
};