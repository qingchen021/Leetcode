/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/


class Solution {
public:
	int trailingZeroes(int n) { //C++
		if (n <= 0)
			return 0;
		int num = 0;
		int size;
		while (n != 0){
			size = n / 5;
			num += size;
			n = size;
		}
		return num;
	}
};