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
		int front = x;
		int frontDev = 1;
		int len = 1;
		int frontLeft = x;
		while (frontLeft >= 10)
		{
			frontDev *= 10;
			frontLeft /= 10;
			len += 1;
		}
		int i = 0;
		int back = x;
		int backLeft = x;

		frontLeft = x;
		while (i < len / 2)
		{
			front = frontLeft / frontDev;
			frontLeft = frontLeft % (frontDev);
		    frontDev = frontDev / 10;

			back = backLeft % 10;
			backLeft = backLeft / 10;

			if (front != back)
			{
				return false;
			}
			i++;
		}
		return true;
	}
};