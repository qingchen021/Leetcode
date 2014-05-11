/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
	string convert(string s, int nRows) {
		string ret = "";
		//第一列和第三列列之间的距离，第3列和第五列的距离..
		int movePos = 2 * nRows - 2;
		if (nRows == 1)
			return s;
		//每两列一起的遍历
		for (int i = 0; i < nRows; i++)
		for (int j = i; j < s.length(); j += movePos)
		{			
			ret.append(1, s[j]);
			//第一列和第二列之间的距离
			int pos = j + 2 * (nRows-1 - i);
			if (i != 0 && i != nRows - 1 && pos < s.length())
				ret.append(1, s[pos]);
		}
		return ret;
	}
};