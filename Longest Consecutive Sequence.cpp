/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/
class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        unordered_set<int> hash;
        for(int i = 0 ; i < num.size();i++)
        {
        	hash.insert(num[i]);
        }
        int ret = 0;
        for(int i = 0 ;i <num.size();i++)
        {
        	if(hash.count(num[i]) != 0)
        	{
        		int c = num[i];
        		int up = 0;
        		while(hash.count(++c) != 0)
        		{
        			++up;
        			hash.erase(c);
        		}
        		c = num[i];
        		int down = 0;
        		while(hash.count(--c))
        		{
        			++down;
        			hash.erase(c);
        		}
        		ret = max(ret, up+down+1);
        	}
        }
        return ret;
    }
};