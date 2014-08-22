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
        int begin = 0, end = n-1;
        int low = -1;
        while(begin<=end)
        {
            int mid = begin + (end - begin)/2;
            if(A[mid] >= target)
            {
                if(A[mid]==target)
                    low = mid;
                end = mid -1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        int high = -1;
        begin = 0, end = n-1;
        while(begin<=end)
        {
            int mid = begin +(end-begin)/2;
            if(A[mid]<=target)
            {
                if(A[mid]==target)
                    high = mid;
               begin = mid +1;
            }
            else
                end = mid -1;
        }
        vector<int> ret;
        ret.push_back(low);
        ret.push_back(high);
        return ret;
    }
};