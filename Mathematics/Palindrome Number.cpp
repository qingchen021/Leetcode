/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution {
 public:
	 bool isPalindrome(int x) {
	      if (x < 0)
			 return false;
		 int bits = 0;
		 long long h = 1;
		 int n = x;
		 while (n)
		 {
			 bits++;
			 h *= 10;
			 n = n / 10;
		 }
		 if (h>1)
			 h /= 10;
		 while (bits > 0)
		 {
			 int left = x / h;
			 int right = x % 10;
			 if (left != right)
				 return false;
			 x = x - left * h;
			 x = x - right;
			 x /= 10;
			 h /= 100;
			 bits -= 2;
		 }
		 return true;
	 }
 };