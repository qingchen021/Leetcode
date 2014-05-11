/*
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int pre = 0;
        int start = 0;
        //1. 如果total大于0,必然存在.
        //2. 如果上次的pre小于0,那么代表开始的点不是当前的start到当前这个点前面一个点的所有的点，
        //因为从start到前面每个点都是至少加上了pre(pre>0)，所有如果是其中的某个的任何一点，那么此时pre还会更小。
        //所以就否定了
        for(int i = 0 ;i < gas.size();i++)
        {
        	int c = gas[i] - cost[i];
        	if(pre >=0 )
        	{
        		pre += c;
        	}
        	else
        	{
        		pre = c;
        		start = i;
        	}
        	total += c;
        }
        if(total < 0)
        	return -1;
        else
        	return start;
    }
};