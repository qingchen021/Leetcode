/*
 Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		vector<int> steps;
		permute(0, num.size()-1, steps, num, res);
		return res;
	}
	//此题目跟combination 题目非常相似，只不过这里面有个顺序因素
	void permute(int begin, int end, vector<int> & steps, vector<int> & num, vector<vector<int> > & res)
	{
		if (steps.size() == num.size())
		{
			res.push_back(steps);
			return;
		}
		else
		{
			for (int i = begin; i <= end; i++)
			{
				//变换一下顺序，搜索的结果也是不一样的
				swap(num[i], num[begin]);
				steps.push_back(num[begin]);
				permute(begin + 1, end, steps, num, res);
				steps.pop_back();
				swap(num[i], num[begin]);
			}

		}
	}
};