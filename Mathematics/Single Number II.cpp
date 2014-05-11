/*
 Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int ans = 0;
        for(int i = 0 ;i < 32; i++)
        {
        	int times = 0 , cur = 1 << i; 
        	for(int j = 0 ; j < n ;j++)
        	{
        		if(cur & A[j])
        			times++;
        	}
        	if(times % 3 )
        		ans |= cur;
        }
        return ans;
    }
};