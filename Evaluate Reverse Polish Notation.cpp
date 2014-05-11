/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        //思路就是碰到operator就将stack里面的元素pop 两个出来，进行计算
        for(int i = 0 ;i < tokens.size() ;i++)
        {
        	char c = tokens[i][0];
        	//注意负号的情况下
        	if((c >='0' && c <='9') || (c == '-' && tokens[i].length() > 1))
        	{
        	 	int num ;
        	 	if(c=='-')
        	 	{
        	 		num = atoi(tokens[i].c_str()+1);
        	 		num = -num;
        	 	}
        	 	else
        	 	{
        	 		num = atoi(tokens[i].c_str());
        	 	}        		
        		nums.push(num);
        	}
        	else
        	{
        		//先出来的是第二个数
        		int second = nums.top();
        		nums.pop();
        		//后出来的是第一个数
        		int first = nums.top();
        		nums.pop();
        		int result ;
        		if(c == '+')
        			result = first + second;
        		if(c == '-')
        			result = first - second;
        		if(c == '*')
        			result = first * second;
        		if(c == '/')
        			result = first / second;
        		nums.push(result);
        	}
        }
        return nums.top();
    }
};