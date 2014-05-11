/*
Divide two integers without using multiplication, division and mod operator. 
*/

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long p = 1;
		//主要是考虑溢出用longlong
		long long dividendLong = dividend, divisorLong = divisor;
		if (dividend < 0 || divisor < 0)
		{
			if (dividendLong < 0 && divisorLong < 0)
				p = 1;
			else
				p = -1;
			if (dividendLong < 0)
				dividendLong = -dividendLong;
			if (divisorLong < 0)
				divisorLong = -divisorLong;
		}
		long long begin = 0, end = dividendLong;
		long long lastSmaller;
		while (begin <= end)
		{
			long long mid = (begin + end) / 2;
			long long tmp = mid *divisorLong;
			if (tmp == dividendLong)
			{
				return mid * p;
			}
			else if (tmp > dividendLong)
			{
				end = mid - 1;
			}
			else
			{
				lastSmaller = mid;
				begin = mid + 1;
			}
		}
		return lastSmaller * p;
	}
};