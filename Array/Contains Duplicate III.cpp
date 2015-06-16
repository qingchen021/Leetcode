/*
Given an array of integers,
find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
*/

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<int, int> hash;
		int start = 0, end = 0;
		for (; end < nums.size();)
		{
			if (end - start > k)
			{
				hash.erase(nums[start++]);
			}
			else
			{
				auto it = hash.lower_bound(nums[end] - t);
				if (it != hash.end() && abs(it->first - nums[end]) <= t)
				{
					return true;
				}
				hash[nums[end++]] = nums[end];
			}
		}
		return false;
	}
};