/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product. 

For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6. 

*/

class Solution {
public:
	int maxProduct(int A[], int n)
	{
		int maxP = A[0], minP = A[0];
		int ret = A[0];
		for (int i = 1; i < n; i++)
		{
			int f1 = maxP* A[i], f2 = minP*A[i];
			maxP = max(f1, max(f2, A[i]));
			minP = min(f1, min(f2, A[i]));
			if (maxP < minP)
				swap(maxP, minP);

			ret = max(ret, maxP);
		}
		return ret;
	}

};