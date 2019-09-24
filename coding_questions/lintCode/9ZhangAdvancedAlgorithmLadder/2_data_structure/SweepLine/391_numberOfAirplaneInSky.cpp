/*
Given an list interval, which are taking off and landing time of the flight. 
How many airplanes are there at most at the same time in the sky?

Example 1:

Input: [(1, 10), (2, 3), (5, 8), (4, 7)]
Output: 3
Explanation:
The first airplane takes off at 1 and lands at 10.
The second ariplane takes off at 2 and lands at 3.
The third ariplane takes off at 5 and lands at 8.
The forth ariplane takes off at 4 and lands at 7.
During 5 to 6, there are three airplanes in the sky.

Input: [(1, 2), (2, 3), (3, 4)]
Output: 1
Explanation: Landing happen before taking off.
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
class TPoint {
public:
    int time;
    int flag;   // 0 land, 1 take off
    
    TPoint() {}
    
    TPoint(int time, int flag)
        : time(time)
        , flag(flag) {}

    bool operator < (const TPoint& rhs) const {
        return time < rhs.time || (time == rhs.time && flag < rhs.flag); 
    }
};

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int n = airplanes.size();
        vector<TPoint> p;
        for (int i = 0; i < n; i++)
        {
            p.push_back(TPoint(airplanes[i].start, 1));
            p.push_back(TPoint(airplanes[i].end, 0));
        }
        
        sort(p.begin(), p.end());
        
        int res = 0, cnt = 0;
        for (int i = 0; i < n * 2; i++)
        {
            if (p[i].flag)
                cnt++;
            else
                cnt--;
            res = max(res, cnt);
        }
        
        return res;
    }
};