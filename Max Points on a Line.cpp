/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()==0)
            return 0;
        int ret = 1;
        for(int i = 0 ;i < points.size();i++)
        {
            unordered_map<double,int> hash;
            int unlimit = 0;
            int same = 1;
            for(int j = 0; j < points.size();j++)
            {
                if(i==j)
                    continue;
                if(points[j].x - points[i].x == 0)
                {
                    if(points[j].y - points[i].y==0)
                    {
                        same++;
                        if(same>ret)
                            ret = same;
                    }
                    else
                    {
                        unlimit++;
                        if(unlimit+same>ret)
                            ret = unlimit+same;
                    }
                }
                else
                {
                    double h = double(points[j].y - points[i].y)/(points[j].x - points[i].x);
                    if(hash.find(h)!=hash.end())
                    {
                        hash[h]++;
                    }
                    else
                        hash[h] = 1;
                    if(hash[h]+same>ret)
                        ret = hash[h]+same;
                }
            }
        }
        return ret;
    }
};