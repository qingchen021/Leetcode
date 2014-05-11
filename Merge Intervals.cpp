/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
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
    vector<Interval> merge(vector<Interval> &intervals) {
    	sort(intervals.begin(), intervals.end(),compare);
        vector<Interval> ret;
        if(intervals.size() == 0)
        	return ret;
        Interval cur = intervals[0];
        for(int i = 0 ;i <= intervals.size() ;i++)
        {
        	if(intervals[i].start > cur.end || i == intervals.size())
        	{
        		ret.push_back(cur);
        		if(i <intervals.size())
        		    cur = intervals[i];
        	}
        	else
        	{
        		if(intervals[i].end > cur.end)
        			cur.end = intervals[i].end ;
        	}
        }
        return ret;
    }

   static bool compare(Interval  first, Interval  sec)
    {
    	return first.start < sec.start;
    }
};