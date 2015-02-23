/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = n-1;
        int index = 0;
        while(index<=end)
        {
            if(A[index] == elem)
            {
                while(end >= index && A[end] == elem)
                    --end;
                if(end>index)
                    swap(A[index],A[end]);
            }
            else
                index++;
        }
        return index;
    }
};