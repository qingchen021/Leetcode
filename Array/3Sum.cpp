/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)

*/

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num)
  {
    sort(num.begin(), num.end());
    vector<vector<int> > res;
    for (int i = 0; i < num.size(); i++)
    {
      int begin = i + 1;
      int end = num.size() - 1;
      if (i == 0 || num[i] > num[i - 1])
      {
        while (begin < end)
        {
          int sum = num[begin] + num[end];
          if (sum == -num[i])
          {
            vector<int> tmp;
            tmp.push_back(num[i]);
            tmp.push_back(num[begin]);
            tmp.push_back(num[end]);
            res.push_back(tmp);
            while (++begin < end && num[begin] == num[begin - 1]);
            while (begin < --end && num[end] == num[end + 1]);
          }
          else if (sum > -num[i])
            end--;
          else
            begin++;
        }
      }
    }
    return res;
  }
};