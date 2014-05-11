/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

*/

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        vector<int> nums;
        bool negative = x < 0;
        if(negative) 
            x = -x;
        while(x)
        {
            nums.push_back(x%10);
            x = x/10;
        }
        int ret = 0;
        int len = 0;
        while(len <= nums.size() -1)
        {
            if(ret == 0)
            {
                if(nums[len] == 0)
                {
                    len++;
                    continue;
                }
                else
                {
                        ret = nums[len];
                        len++;
                }
            }
            else
            {
                ret = ret * 10;
                ret += nums[len];
                len++;
            }            
        }
        if(negative)
            ret = -ret;
        return ret;
    }
};