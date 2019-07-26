/*
335. Self Crossing My Submissions QuestionEditorial Solution
Total Accepted: 4002 Total Submissions: 22172 Difficulty: Medium
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)
Example 2:
Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
Example 3:
Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>

Return true (self crossing)
*/


//solution: only these three types will cause self cross
/*               i-2
    case 1 : i-1┌─┐
                └─┼─>i
                 i-3

                    i-2
    case 2 : i-1 ┌────┐
                 └─══>┘i-3
                 i  i-4      (i overlapped i-4)

    case 3 :    i-4
               ┌──┐ 
               │i<┼─┐
            i-3│ i-5│i-1
               └────┘
                i-2

*/


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.empty() || x.size() < 4) 
            return false;
        
        for(int i=3;i<x.size();i++){
            if(x[i]>=x[i-2]&&x[i-1]<=x[i-3]){  //case 1
                return true;
            }else if(i>=4 && x[i-1]==x[i-3] && x[i] + x[i-4] >= x[i-2]){ //case2
                return true;
            }else if(i>=5 && x[i-1]<=x[i-3] && x[i-1]>=x[i-3]-x[i-5] && x[i-2]>= x[i-4] && x[i]>=x[i-2]-x[i-4]){ //case3
                return true;
            }
        }  
        
        return false;
    }
};

int main(){

    return 0;
}