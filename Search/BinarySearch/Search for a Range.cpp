/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

 class Solution
 {

 public:

	 vector<int> searchRange(int A[], int n, int target)
	 {


		 vector<int> ret;
		 int first = BinarySearch(A, 0, n - 1, target, -1);
		 if (first == -1)
		 {
			 ret.push_back(-1);
			 ret.push_back(-1);
			 return ret;
		 }
		 else
		 {
			 ret.push_back(first);
			 if (first == n - 1)
				 ret.push_back(first);
			 else{
				 int second = BinarySearch(A, first + 1, n - 1, target, 1);
				 if (second == -1)
					 ret.push_back(first);
				 else
					 ret.push_back(second);
			 }
			 return ret;
		 }

	 }

	 int BinarySearch(int A[], int first, int last, int target, int direction)
	 {
		 int begin = first, end = last;
		 while (begin <= end)
		 {
			 int mid = (begin + end) / 2;
			 if (A[mid] == target)
			 {
				 if ((direction > 0 && mid == last) || (direction < 0 && mid == first))
					 return mid;
				 else if (A[mid + direction] != target)
					 return mid;
				 else
				 {
					 if (direction > 0)
						 begin = mid + 1;
					 else
						 end = mid - 1;
				 }

			 }
			 else if (A[mid] > target)
			 {
				 end = mid - 1;
			 }
			 else
				 begin = mid + 1;
		 }
		 return -1;
	 }
 };