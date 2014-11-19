/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		int pre = A[0];
		int curSize = 1;
		int repeatTimes = 1;
		for (int i = 1; i < n; i++)
		{
			if (A[i] != pre)
			{
				A[curSize++] = A[i];
				pre = A[i];
				repeatTimes = 1;
			}
			else if (repeatTimes < 2)
			{
				A[curSize++] = A[i];
				repeatTimes++;
			}
		}
		return curSize;
	}
};

};