/*
Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

Have you met this question in a real interview? Yes
Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3
*/

/*
binary search
*/

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x==0)  
            return 0;
        if(x==1)
            return 1;
        
        int left = 0;
        int right  = x;
        
        while(left<=right){
            int mid = (right - left)/2 + left;
            //cout<<mid<<endl;
            
            if(mid == x/mid)
                return mid;
            else if(mid<x/mid){
                left  = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        //cout<<left<<" "<<right<<endl;
        
        return min(left,right);
    }
};

int main(){

	return 0;
}