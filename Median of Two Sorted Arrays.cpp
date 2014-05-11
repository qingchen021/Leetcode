/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n ;
        if(total%2 == 1)
        	return FMS(A,m,B,n,total/2+1);
        else
        	return (FMS(A,m,B,n,total/2+1) + FMS(A,m,B,n,total/2))/2;

    }

    double FMS(int a[], int m , int b[], int n, const int k)
    {
    	if(m > n )
    		return FMS(b,n,a,m,k);
    	if(m == 0)
    		return b[k-1];
    	if(k == 1)
    		return min(a[0],b[0]);
    	int pa = min(m,k/2);
    	int pb = k - pa;
    	if(a[pa-1] < b[pb-1])
    		return FMS(a+pa,m-pa,b,n,k-pa);
    	else
    		return FMS(a,m,b+pb,n-pb,k-pb);
    }
};