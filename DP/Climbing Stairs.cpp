/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
*/

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n == 1)
            return 1;
        int pre = 1, prePre = 2;
        for(int i = 3;i<=n;i++)
        {
            pre = prePre + pre;
            swap(pre,prePre);
        }
        return max(prePre,pre);
    }
};