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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int firstIndex = 0, secondIndex = 0;
		int firstFound = false, secondFound = false;
		firstFound = BinarySearch(intervals, newInterval.start, firstIndex);
		secondFound = BinarySearch(intervals, newInterval.end, secondIndex);
		//分两种，一种newInterval没有跨度的时候，另一种newInterval 至少跨度一个
		if (firstIndex == secondIndex)
		{
			//都没有重合的话，直接插入该元素
			if (!firstFound && !secondFound)
			{
				intervals.insert(intervals.begin() + firstIndex, Interval(newInterval.start, newInterval.end));
			}
			else
			{
				//更新该元素的start 和 end
				int start = min(intervals[firstIndex].start, newInterval.start);
				int end = max(intervals[firstIndex].end, newInterval.end);
				intervals[firstIndex].start = start;
				intervals[firstIndex].end = end;
			}
		}
		//至少一个有一个跨度的情况下
		else
		{
			int start = newInterval.start, end = newInterval.end;
			int startIndex = firstIndex , endIndex = secondIndex;
			//不管firstFound找都或者没找到，startIndex不会变,因为是把startIndex和endIndex之间都删掉
			//但是要更新下start
			if (firstFound)
			{
				start = min(intervals[firstIndex].start, start);
			}
			//如果endIndex是找到的，那么要包括该元素，即endIndex要加1
			if (secondFound)
			{
				endIndex++;
				end = max(intervals[secondIndex].end, end);
			}
			intervals.erase(intervals.begin() + startIndex, intervals.begin() + endIndex);
			intervals.insert(intervals.begin() + startIndex, Interval(start, end));
		}
		return intervals;
	}

	//返回的值为该元素的应该在这个数组的位置
	//这个二分查找，要返回两个值，一个该元素插入的值和是否是找到该值
	bool BinarySearch(const vector<Interval> &intervals, int i, int & index)
	{
		int begin = 0, end = intervals.size() - 1;
		int lastSmall;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (i <= intervals[mid].end && i >= intervals[mid].start)
			{
				index = mid;
				return true;
			}
			else if (i > intervals[mid].end)
			{
				//假如begin == end 这个时候，要取begin+1 ,而不是end-1
				begin = mid + 1;
				index = begin;
			}
			else
			{
				end = mid - 1;				
			}
		}
		return false;
	}
};
