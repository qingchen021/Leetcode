/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret = 0;
	int begin = 0, end = height.size() -1;
	while(begin < end)
	{
		int h = min(height[begin], height[end]);		
		ret = max(ret, (end- begin) * h);
		if( height[begin] == h)
		{
			while(begin < end && height[begin++] < h);
		}
		else
			while(begin < end && height[end--] < h);
	}
	return ret;
    }
};