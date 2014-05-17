/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 
*/

class Solution {
	struct Node
	{
		int h, p;
		Node(int height, int pos):h(height),p(pos){}
	};
public:
    //主要考察的是当前的高度左右延伸的距离，这可以用栈来完成
	int largestRectangleArea(vector<int> &height) {
		int ret = 0;
		stack<Node> hStack;
		for(int i = 0; i < height.size() ;i++)
		{
			if(! hStack.empty())
			{
				Node top = hStack.top();
				Node n(height[i],0);
				//如果当前元素比栈顶元素小，那么栈顶元素最右边就是当前index的前一个了
				if(top.h > height[i])
				{
				    //这里要确定所有栈内的元素都比当前push进去的元素要小
					while (top.h > height[i])
					{
					    //每次pop之前更新当前元素最左端位置
						n.p = top.p;
						ret = max(ret , top.h *(i - top.p));
						hStack.pop();
						if(!hStack.empty())
							top = hStack.top();
						else
						{
							break;
						}
					}		
				}
				else
				//如果当前原始比栈顶元素大，那么当前元素最长左边就是自己index了，
					n.p = i;
				hStack.push(n);				
			}
			else
				hStack.push(Node(height[i],i));
		}
		int last = height.size() -1;
		//如果遍历完，栈里面还有元素，代表，它们最右边的边界就是len－1
		while(!hStack.empty())
		{
			Node top = hStack.top();
			ret = max(ret , top.h *(last - top.p + 1));
			hStack.pop();
		}
		return ret;
	}
};