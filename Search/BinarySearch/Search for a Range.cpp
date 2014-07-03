/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lowBound = -1, highBound = -1;
        int low = 0 , high = n-1;
        vector<int> ret ;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(A[mid]>=target)
            {
                lowBound = mid;
                high = mid -1;
            }
            else
            {
                low = mid +1;
            }
        }
        
        if(lowBound!=-1)
        {
            if(A[lowBound]!=target)
                lowBound = -1;
        }
        low = 0;
        high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(A[mid]<=target)
            {
                highBound = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
         if(highBound!=-1)
        {
            if(A[highBound]!=target)
                highBound = -1;
        }
        ret.push_back(lowBound);
        ret.push_back(highBound);
        return ret;
    }
};