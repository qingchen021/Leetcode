/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
*/

class Solution {
 public:
	 int removeElement(int A[], int n, int elem) {
		 if (n == 0 || (n == 1 && A[0] == elem))
			 return 0;
		 int begin = 0, end = n - 1;
		 while (begin <= end)
		 {
			 if (A[begin] == elem)
			 {
				 while (begin <= end && A[end] == elem)
				 {
					 end--;
				 }
				 if (begin < end)
				 {
					 A[begin] = A[end];
					 end--;
				 }
				 else
				 {
					 end = begin - 1;
				 }
			 }
			 begin++;
		 }
		 return end + 1;
	 }
 };