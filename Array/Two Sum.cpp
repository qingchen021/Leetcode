/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/

class Solution {
    struct Num
    {
    	Num(int v, int p):val(v),pos(p){}
    	int val;
    	int pos;
    };
    struct NumCompare {
        bool operator() (const Num & i,const Num & j) { return (i.val < j.val);}
    } numCompareObject;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret ;
        int len = numbers.size();
        if(len == 0) return ret;
        vector<Num> nums;
        for(int i = 0 ;i < len ;i++)
        {
        	nums.push_back(Num(numbers[i],i+1));
        }
        sort(nums.begin(), nums.end(),numCompareObject);
        
        for(int begin = 1 ,end = len; begin<= end ;)
        {
        	int sum = nums[begin-1].val + nums[end-1].val;
        	if(sum == target)
        	{
        		int front = min(nums[end-1].pos, nums[begin-1].pos);
        		int back = max(nums[end-1].pos,nums[begin-1].pos);
        		ret.push_back(front);
        		ret.push_back(back);
        		break;
        	}
        	else if(sum > target)
        	{
        		end--;
        	}
        	else
        		begin++;
        }
        return ret;
    }
};