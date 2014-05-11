/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0 , end = n -1 ;
        while(begin <= end)
        {
        	int mid = end - (end - begin)/2;
        	if(A[mid] == target)
        		return true;
        	if(A[mid] > A[begin])
        	{
        		if(target < A[mid] && target >= A[begin])
        			end = mid -1;
        		else
        			begin = mid + 1;
        	}
        	else if(A[mid] < A[begin])
        	{
        		if(target > A[mid] && target <= A[end])
        			begin = mid + 1;
        		else
        			end = mid -1;
        	}
        	else
        		begin++;
        }
        return false;
    }
};