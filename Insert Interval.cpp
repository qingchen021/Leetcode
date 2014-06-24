/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		int l = intervals.size(), h = -1;
		int low = 0, high = intervals.size() - 1;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (intervals[mid].start > newInterval.end)
				high = mid - 1;
			else
			{
				h = mid;
				low = mid + 1;
			}
		}
		low = 0, high = intervals.size() - 1;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (intervals[mid].end < newInterval.start)
				low = mid + 1;
			else
			{
				l = mid;
				high = mid - 1;
			}
		}
		if (l == h)
		{
			intervals[l].start = min(intervals[l].start, newInterval.start);
			intervals[l].end = max(intervals[l].end, newInterval.end);
		}
		else if (l > h)
		{
			intervals.insert(intervals.begin() + l, newInterval);
		}
		else
		{
			newInterval.start = min(newInterval.start, intervals[l].start);
			newInterval.end = max(newInterval.end, intervals[h].end);
			intervals.erase(intervals.begin() + l, intervals.begin() + h + 1);
			intervals.insert(intervals.begin() + l, newInterval);
		}
		return intervals;
	}
};