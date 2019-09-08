/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

/*
O(n)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        // if(num.empty()) 
        int min = num[0];
        
        for (int i = 1; i < num.length; i++) {
            if (num[i] < min)
                min = num[i];
        }

        return min;
    }
};
int main(){

	return 0;
}