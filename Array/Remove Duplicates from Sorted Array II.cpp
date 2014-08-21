/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0||n==1)
            return n;
        int pre = A[0];
        int curIndex = 0;
        int repeatTime = 1;
        for(int i = 1 ;i < n;i++)
        {
            if(pre == A[i])
                repeatTime += 1;
            if(pre != A[i] || repeatTime < 3)
            {
                curIndex++;
                A[curIndex] = A[i];
                if(pre!=A[i])
                    repeatTime = 1;
            }
            pre = A[i];
        }
        return curIndex+1;
    }
};