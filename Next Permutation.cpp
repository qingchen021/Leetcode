/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
	 if(num.size() == 0) return ;
	 int size = num.size();
	 int tillNowBiggest = num[size - 1];
     	 for(int i = size - 2 ;i >= 0 ;i--)
	 {
		if(num[i] >= tillNowBiggest)
		{
			tillNowBiggest = num[i];
		}
		else
		{	
			sort(num.begin() + i + 1, num.end());
			auto firstBigIndex = upper_bound(num.begin() + i +1, num.end(), num[i]);
			swap(num[i], *firstBigIndex);
			return ;
		}
	}
	sort(num.begin(), num.end());
    }
};