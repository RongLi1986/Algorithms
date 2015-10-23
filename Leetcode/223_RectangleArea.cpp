/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

rectangle1: bottom left: (A,B), top right:(C,D)
rectangle2: bottom left: (E,F), top right:(G,H)


Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/


/*
//How to caculate overlap area?
case 1: no overlap: overlap area is 0
case 2: overlap happen on one edge
case 3 overlap happen on two edges
case 4 one rectangle is in another rectangle.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum=(G-E)*(H-F)+(C-A)*(D-B);
        
        //case 1
        if(E>C||A>G||F>D||B>H) return sum;
        
        //other overlap area's caculation
        //(min(G,C)-max(E,A))*(min(H,D)-max(F,B)) is overlap area
        
        return sum-(min(G,C)-max(E,A))*(min(H,D)-max(F,B));

    }
};


int main(){

  Solution s;
  cout<<s.computeArea(0,0,1,1,2,2,3,3)<<endl;

  return 0;
}