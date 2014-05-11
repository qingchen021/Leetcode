/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once.
        vector<vector<int>> res;
    	int numlen = num.size();
		if(num.size()<4)return res;
		
		sort(num.begin(),num.end());
		set<vector<int>> tmpres;
		for(int i = 0; i < numlen; i++)
		{
			for(int j = i+1; j < numlen; j++)
			{
				int begin = j+1;
				int end = numlen-1;
				while(begin < end)
				{
					int sum = num[i]+ num[j] + num[begin] + num[end];
					if(sum == target)
					{
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[begin]);
						tmp.push_back(num[end]);
						tmpres.insert(tmp);
						begin++;
						end--;
					}else if(sum<target)
						begin++;
					else
						end--;
				}
			}
		}
		set<vector<int>>::iterator it = tmpres.begin();
		for(; it != tmpres.end(); it++)
			res.push_back(*it);
		return res;
    }
};