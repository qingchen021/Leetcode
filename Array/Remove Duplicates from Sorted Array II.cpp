/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
        	return 0;
        int pre = A[0];
        int times = 1;
        int index = 1;
        for(int i = 1; i < n ;i++)
        {
        	if(A[i] == pre)
        	{
        		if(times==2)
        		{
        			continue;
        		}
        		else
        		{
        			times++;
        			A[index++] = A[i];
        		}
        	}
        	else
        	{
        		pre = A[i];
        		times = 1;
        		A[index++]=A[i];
        	}
        }
        return index;
    }
};