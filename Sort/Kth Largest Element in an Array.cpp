/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 = k = array's length.
*/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		return findKthLargest(nums, 0, nums.size() - 1, k);
	}

	int findKthLargest(vector<int>& nums, int begin, int end, const int k)
	{
		int nn = nums.size() - k;
		int n = partition(nums, begin, end);
		if (n == nn)
			return nums[n];
		else if (n > nn)
		{
			return findKthLargest(nums, begin, n - 1, k);
		}
		else
		{
			return findKthLargest(nums, n + 1, end, k);
		}
	}

	int partition(vector<int>& nums, int begin, int end)
	{
		int p = nums[begin], last = begin , bb = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (nums[i] <= p)
			{
				swap(nums[i],nums[++last]);
			}
		}
		swap(nums[last],nums[bb]);
		return last;
	}
};