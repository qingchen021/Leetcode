/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

 class Solution {
 public:
	 int numDecodings(string s) {
		 int len = s.length();
		 if (len == 0)
			 return 0;
		 int *arry = new int[len + 1];
		 arry[0] = 1;
		 if (s[0] == '0')
			 arry[1] = 0;
		 else
			 arry[1] = 1;
		 for (int i = 2; i <= len; i++)
		 {
			 int p1 = 0;
			 int p2 = 0;
			 if (s[i - 1] == '0')
			 {
				 p1 = 0;
			 }
			 else
			 {
				 p1 = arry[i - 1];
			 }
			 if (s[i - 2] - '0' < 3 && s[i - 2] - '0' > 0)
			 {
			     if(s[i-2] == '2')
			     {
			         if(s[i-1] > '6')
			         {
			             p2 = 0;
			         }
			         else
			            p2 = arry[i - 2];
			     }
			     else
				    p2 = arry[i - 2];
			 }
			 else
				 p2 = 0;
			 arry[i] = p1 + p2;
		 }
		 return arry[len];
	 }
 };
