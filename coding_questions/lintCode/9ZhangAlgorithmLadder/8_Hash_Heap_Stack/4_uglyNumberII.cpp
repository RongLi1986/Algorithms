/*
Ugly Number II

 Description
 Notes
 Testcase
 Judge
Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

 Notice

Note that 1 is typically treated as an ugly number.

Have you met this question in a real interview? Yes
Example
If n=9, return 10.
*/


/*
BFS
it need to consider overflow!
*/

class Solution {
private:
    priority_queue<long, vector<long>, std::greater<long> > pQueue;
    unordered_map<long, int> visitorMap;

public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        if(n<=0) return 0;
        int count=0;
        pQueue.push(1);
        visitorMap[1] = 1;
        long topValue = 1;
        while(1){
            topValue = pQueue.top();
            //cout<<topValue<<endl;
            pQueue.pop();
            count++;
            if(count==n)
                break;
            
            if((topValue*2>0) && visitorMap.find(topValue*2)==visitorMap.end()){
                pQueue.push(topValue*2);
                visitorMap[topValue*2] = 1;
            }
            
            if((topValue*3>0) && visitorMap.find(topValue*3)==visitorMap.end()){
                pQueue.push(topValue*3);
                visitorMap[topValue*3] = 1;
            }
            
            if((topValue*5>0) && visitorMap.find(topValue*5)==visitorMap.end()){
                pQueue.push(topValue*5);
                visitorMap[topValue*5] = 1;
            }
        }
        
        //cout<<topValue<<endl;
        return topValue;
    }
}