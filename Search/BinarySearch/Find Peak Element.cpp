/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
       int low = 0, high = num.size()-1;
       while(low<high)
       {
           int mid = low + (high - low)/2;
           if((mid == 0||num[mid] > num[mid-1]) &&
              (mid == high || num[mid] > num[mid+1]))
                return mid;
            else if(num[mid]>num[mid+1])
                high = mid;
            else
                low = mid+1;
       }
       return low;
    }
};