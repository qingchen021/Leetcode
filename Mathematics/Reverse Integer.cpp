/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

*/

 class Solution {
 public:
	 int reverse(int x) {
		 int p = 1;
		 long long n = 0;
		 long long xL = x;
		 if (xL<0)
		 {
			 p = -1;
			 xL = -xL;
		 }
		 while (xL)
		 {
			 n *= 10;
			 n += xL % 10;
			 xL = xL / 10;
		 }
		 if (n > INT_MAX || (p == -1 && -n <= INT_MIN))
			 return 0;
		 return n * p;
	 }
 };