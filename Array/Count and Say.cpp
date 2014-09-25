/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string
*/

 class Solution {
 public:
	 string countAndSay(int n) {
		 string num = "1";
		 for (int j = n-1; j > 0; --j)
		 {
			 string cur = "";
			 char pre = num[0];
			 int preTimes = 0;
			 for (int i = 0; i <= num.length(); i++)
			 {
				 if (i<num.length() && num[i] == pre)
				 {
					 preTimes++;
				 }
				 else
				 {
					 char times = preTimes + '0';
					 cur.append(1, times);
					 cur.append(1, pre);
					 if (i < num.length())
					 {
						 pre = num[i];
						 preTimes = 1;
					 }
				 }
			 }
			 num = cur;
		 }
		 return num;
	 }
 };