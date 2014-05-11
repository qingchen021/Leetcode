/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
*/

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<int> steps;
		vector<vector<int> > res;
		permuteUnique(0, num.size() - 1, steps, num, res);
		return res;
	}

	bool NeedSwap(int n, int begin, const vector<int> & num)
	{
		for (int i = begin; i < n; i++)
		{
			if (num[i] == num[n])
				return false;
		}
		return true;
	}

    //下面这句话很重要，体现在NeedSwap上，不单纯是非与当前元素非相同，必须与其之间的所有的元素都不相同
	//去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换
	
	//还有个总结
	//http://blog.csdn.net/xx77009833/article/details/17843415
	//至此我们已经运用了递归与非递归的方法解决了全排列问题，总结一下就是：
	//1．全排列就是从第一个数字起每个数分别与它后面的数字交换。
	//2．去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。
	//3．全排列的非递归就是由后向前找替换数和替换点，然后由后向前找第一个比替换数大的数与替换数交换,颠倒替换点后的所有数据(NextPerm)
	void permuteUnique(int begin, int end, vector<int> & steps, vector<int> & num, vector<vector<int> > & res)
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
				if (i != begin && !NeedSwap(i, begin, num))
				{
					continue;
				}
				else
				{
					swap(num[i], num[begin]);
					steps.push_back(num[begin]);
					permuteUnique(begin + 1, end, steps, num, res);
					steps.pop_back();
					swap(num[i], num[begin]);
				}
			}
		}
	}

};