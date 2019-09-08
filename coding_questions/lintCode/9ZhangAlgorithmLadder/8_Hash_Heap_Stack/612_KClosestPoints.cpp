/*
K Closest Points

Given some points and a point origin in two dimensional space, find k points out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.

Have you met this question in a real interview? Yes
Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]
*/


/*

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
 
class mycomparison
{
public:
    mycomparison(){
      
    }
    
    bool operator() (const pair<Point,int>& lhs, const pair<Point,int>&rhs) const
    {
        if(lhs.second == rhs.second){
            if(lhs.first.x==rhs.first.x){
                return lhs.first.y < rhs.first.y;
            }else{
                return lhs.first.x < rhs.first.x;
            }
        }else{
            return lhs.second > rhs.second;  //less
        }
    }
};

class Solution {
public:
    /**
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     */
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        // Write your code here
        priority_queue<pair<Point,int>, vector<pair<Point,int> >, mycomparison> queue;
        vector<Point> res;
        
        for(int i =0; i<points.size();i++){
            int distance = pow(origin.x - points[i].x, 2) + pow(origin.y - points[i].y, 2);
            pair<Point,int> it;
            it = make_pair(points[i], distance);
            queue.push(it);
        }
        
        int len = queue.size();
        //cout<<len<<endl;
        int s = min(len, k);
        for(int i = 0;i<s;i++){
            pair<Point, int> it = queue.top();
            queue.pop();
            res.push_back(it.first);
        }
        
        return res;
    }
};