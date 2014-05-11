/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
       vector<int> nums;
       int d(1);
       string ret("");
       for(int i = 1 ; i <= n ;i++)
       {       	
       		nums.push_back(i);
       		d *= i;
       }

      for(int i = n ;i >= 1;--i)
       {
       		d = d / i;
       		int nth = (k -1) / d;
       		k  = k - nth * d ;
       		int c = nums[nth];
       		ret.append(1, c + '0');
       		nums.erase(nums.begin() + nth);
       }
       return ret;
    }
};