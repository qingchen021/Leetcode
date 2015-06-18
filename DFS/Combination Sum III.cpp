/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> steps;
        combinationSum3(k,n,1,0,steps,ret);
        return ret;
    }
    
    void combinationSum3(int k,int n, int th, int cur, vector<int> & steps,  vector<vector<int>>& res)
    {
        if(steps.size() == k && cur == n)
        {
            res.push_back(steps);
        }
        else
        {
            for(int i = th ;i<=9;i++)
            {
                if(cur+i>n)
                    break;
                else
                {
                    steps.push_back(i);
                    combinationSum3(k,n,i+1,cur+i,steps,res);
                    steps.pop_back();
                }
            }
        }
    }
};