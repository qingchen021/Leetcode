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
		 sort(num.begin(), num.end());
		 vector<vector<int> > ret;
		 for (int i = 0; i < num.size(); i++)
		 {
			 if (i > 0 && num[i] == num[i - 1])
				 continue;
			 for (int j = i + 1; j<num.size(); j++)
			 {
				 if (j > i+1 && num[j] == num[j - 1])
					 continue;
				 int begin = j+1, end = num.size() - 1;
				 while (begin<end)
				 {
					 int sum = num[i] + num[j] + num[begin] + num[end];
					 if (sum == target)
					 {
						 vector<int> r = { num[i], num[j], num[begin], num[end] };
						 ret.push_back(r);
						 while (++begin < end && num[begin] == num[begin - 1])
							 ;
						 while (begin< --end && num[begin] == num[end + 1])
							 ;
					 }
					 else if (sum > target)
						 end--;
					 else
						 begin++;
				 }
			 }
		 }
		 return ret;
	 }
 };
