/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/

class Solution {
public:
    	vector<string> generateParenthesis(int n) {
        vector<string> ret;
		generateParenthesis(0, 0, n, "", ret);
		return ret;
    	}
	void generateParenthesis(int left, int right, int n, string curStr, vector<string> & res)
	{
	    //意味着 左边的括号已经够了，只需要添加右边的括号了
		if(left == n)
		{
			res.push_back(curStr.append(n-right,')'));
			return ;
		}
		else
		{
		    //先添加左边的括号
			generateParenthesis(left + 1, right, n , curStr+"(", res);
			//如果左边的括号数量大于右边的括号，才能进行添加右边的括号
			if(left > right )
				generateParenthesis(left,right+1, n, curStr + ")", res);
		}
	}
};