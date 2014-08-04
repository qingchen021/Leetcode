/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution
 {

 public:

	 string multiply(string num1, string num2)
	 {
		 if (num1 == "0" || num2 == "0")
			 return "0";
		 vector<int> result(num1.size() + num2.size(), 0);
		 for (int i = 0; i < num1.size(); i++)
		 for (int j = 0; j<num2.size(); j++)
		 {
			 result[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
		 }
		 for (int i = num1.size() + num2.size() - 1; i>0; i--)
		 {
			 if (result[i]>9)
			 {
				 result[i - 1] += result[i] / 10;
				 result[i] %= 10;
			 }
		 }
		 string ret = "";
		 int i = 0;
		 while (result[i] == 0)
			 i++;
		 for (; i<num1.size() + num2.size(); i++)
		 {
			 ret.append(1, result[i] + '0');
		 }
		 return ret;
	 }

 };