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
    struct Point
    {
        int x ,y,p;
        Point(int xx,int yy):x(xx),y(yy)
        {
            
        }
    };
public:
    int largestRectangleArea(vector<int> &height) {
        stack<Point> stackS;
        int largest = 0;
        for(int i = 0;i< height.size();i++)
        {
            int mostLeft = i;
            while(true)
            {
                if(!stackS.empty())
                {
                    Point t = stackS.top();
                    if(t.y > height[i])
                    {
                        mostLeft = t.x;
                        largest = max(largest,t.y *(i-t.x));
                        stackS.pop();
                    }
                    else
                    {
                        stackS.push(Point(mostLeft,height[i]));
                        break;
                    }
                }
                else
                {
                    stackS.push(Point(mostLeft,height[i]));
                    break;
                }
            }
        }
        int mostRight = height.size()-1;
        while(!stackS.empty())
        {
             Point top = stackS.top();
             stackS.pop();
             largest = max(largest,top.y *(mostRight - top.x +1));
        }
        return largest;
    }
};