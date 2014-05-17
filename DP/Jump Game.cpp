/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 
*/

class Solution {
public:
    	bool canJump(int A[], int n) {
		int end = 0;
		//看当前end最远能到多远，如果已经超过n-1，便可以退出，否则继续更新n
        for(int i = 0 ; i <= end && end < n-1 ; i++)
		{
			end = max(end ,A[i] + i);
		}
		if(end < n-1)
			return false;
		else
			return true;
    	}	
};