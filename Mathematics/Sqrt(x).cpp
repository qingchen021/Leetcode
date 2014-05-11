/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
	int sqrt(int x) {
		unsigned long long begin = 0, end = x;
		unsigned long long half = 0;
		int ans;
		while (begin <= end)
		{
			half = begin + (end - begin) / 2;
			unsigned long long n = half * half;
			if (n == x)
				return half;
			else if (n > x)
				end = half - 1;
			else
			{
				begin = half + 1;
				//最后一个比x小的
				ans = half;
			}
		}
		return ans;
	}
};