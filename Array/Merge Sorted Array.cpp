/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n -1 ;
	int indexA = m-1 , indexB= n-1;
	while( indexA >= 0  && indexB >=0 )
	{
		int num;
		if(A[indexA] < B[indexB])
		{
			num = B[indexB--];
		}
		else
		{
			num = A[indexA--];
		}
		A[index--] = num;
	}
	while(indexA >= 0)
		A[index--] = A[indexA--];
	while(indexB >= 0)
		A[index--] = B[indexB--];
    }
};