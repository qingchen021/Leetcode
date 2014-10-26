/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/


class Solution {
public:
    int findMin(vector<int> &num) {
        int begin = 0 , end = num.size()-1;
        while(begin<end&&num[begin]>=num[end])
        {
            int mid = begin + (end-begin)/2;
            if(mid>0 && num[mid]<num[mid-1])
                return num[mid];
            else if(num[mid]>num[begin])
                begin = mid+1;
            else if(num[mid]<num[begin])
                end = mid-1;
            else
                begin++;
        }
        return num[begin];
    }
};