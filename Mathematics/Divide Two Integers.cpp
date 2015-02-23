/*
Divide two integers without using multiplication, division and mod operator. 
*/

 class Solution {
 public:
	 int divide(int dividend, int divisor)
	 {
		 int p = 1;
		 long long dividendL = dividend, divisorL = divisor;
		 if (dividendL > 0 ^ divisorL >0)
		 {
			 p = -1;
		 }
		 if (dividendL< 0) dividendL = -dividendL;
		 if (divisorL < 0) divisorL = -divisorL;
		 long long start = 0, end = dividendL;
		 long long  result;
		 while (start <= end)
		 {
			 long long mid = start + (end - start) / 2;
			 long long m = mid * divisorL;
			 if (m == dividendL)
			 {
				 result = mid*p;
				 break;
			 }
			 else if (m < dividendL)
			 {
				 result = mid*p;
				 start = mid + 1;
			 }
			 else
				 end = mid - 1;
		 }
		 if (result >= INT_MAX )
			 return INT_MAX;
		 if (result <= INT_MIN)
			 return INT_MIN;
		 return result;
	 }
 };