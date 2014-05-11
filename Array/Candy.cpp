/*
 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/
class Solution {
public:
    //先左边扫一遍，求安装左边的顺序，需要最小的candy,
	//然后右边扫一遍，每个值取按左边和右边顺序值求得的最大值
    int candy(vector<int> &ratings) {
	    vector<int> candies(ratings.size(),1);
	    for(int i = 1 ;i < ratings.size() ;i++)
	    {
	    	if(ratings[i] > ratings[i-1])
	    		candies[i] = candies[i-1] + 1;
	    }
	    for(int i = ratings.size()-2; i >=0 ;i--)
	    {
	    	if(ratings[i] > ratings[i+1])
	    		candies[i] = max(candies[i],candies[i+1]+1);
	    }
	    int ret = 0;
	    for(int i = 0 ;i < candies.size();i++)
	    	ret += candies[i];
	    return ret;
    }
};