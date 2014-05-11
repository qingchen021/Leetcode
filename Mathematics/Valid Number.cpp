/*

http://oj.leetcode.com/problems/valid-number/

Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
*/

/*
解题思想：

canDot , canE , canSign 分别表示当前状态时是否能为 '.' , 'E/e', '+/-';
needNumber 表示当前状态是否需要至少有一个number （0-9）
blank表示当前空格的位置，0表示最开始，1表示有上述任何一种字符的时候，2表示结尾。

如果blank的位置为2，那么接下来的c必须是' ',否则return false
如果有了+/-，，如果前面已经有数字了，那么当前状态为false，否则，那么接下来的不能有+/-了
如果是number,那么接下来一个字符不能为+/-了
如果是'.'，那么接下来不能使+/-了，
如果是'E/e',前面必须已经有数字，而且那么接下来要needNumber,不能为'+/-',不能dot,
如果是blank，并且前面的blank位置在1，那么接下来blank的位置必须为2

返回的时候必须只有有个数字
*/

class Solution {
public:
	bool isNumber(const char *s) 
	{
	    bool canDot = true, canE = true, canSign = true;
	    bool needNumber = true;
	    int blank = 0;
	    char c ;
	    while(c = *s++)
	    {
	        if(c != ' ' && blank == 2)
	        {
	            return false;
	        }
	        if( c == '+' || c == '-')
	        {
	        	if(!canSign || !needNumber)
	        		return false;
	        	canSign = false;
	        	blank = 1;
	        	continue;
	        }
	        if( c >= '0' && c <= '9')
	        {
	        	needNumber = false;
	        	canSign = false;
	        	blank = 1;
	        	continue;
	        }
	        if( c == '.')
	        {
	        	if(!canDot)
	        		return false;
	        	canDot = false;
	        	canSign = false;
	        	blank = 1;
	        	continue;
	        }
	        if( c == 'E' || c == 'e')
	        {
	        	if(!canE || needNumber)
	        		return false;
	        	canSign = true;
	        	canDot = false;
	        	canE = false;
	        	needNumber = true;
	        	blank = 1;
	        	continue;
	        }
	        if(c == ' ')
	        {
	        	if(blank == 1)
	        		blank = 2;
	        	continue;
	        }
	        return false;
	    }
	    return !needNumber;
	}
};
