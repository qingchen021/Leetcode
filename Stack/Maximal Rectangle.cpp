/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
*/

class Solution {
public:
   int largestRectArea(vector<int> &height) {
    stack<int> p;
    int i = 0, res = 0;
    height.push_back(0);
    while(i < height.size()) {
        if(p.empty() || height[p.top()] <= height[i])
        p.push(i++);
        else {
            int t = p.top();
            p.pop();
            res = max(res, height[t] * (p.empty() ? i : i - p.top() - 1 ));        
        }
    }
    height.pop_back();
    return res;
}
int maximalRectangle(vector<vector<char> > &matrix) {
    int row = matrix.size();
    int column = 0;
    if(row == 0 || (column = matrix.front().size()) == 0)
        return 0;
    int res = 0;
    vector<int> height(column, 0);
    for(int ri = 0; ri < row; ++ri){
        for(int ci = 0; ci < column; ++ci)
            height[ci] = (matrix[ri][ci] == '0' ? 0 : height[ci] + 1);
        res = max(res, largestRectArea(height));
    }
    return res;
}
};