/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

  class Solution {
  public:
	  void rotate(int nums[], int n, int k) {
		  k = k%n;
		  if (k == 0)
			  return;
		  for (int i = 0; i < n / 2; i++)
			  swap(nums[i], nums[n - i - 1]);
		  for (int i = 0; i < k / 2; i++)
			  swap(nums[i], nums[k - i - 1]);
		  for (int i = 0; i < (n - k) / 2; i++)
			  swap(nums[i + k], nums[n - i - 1]);
	  }
  };