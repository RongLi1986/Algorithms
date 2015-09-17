/*Find Minimum in Rotated Sorted Array 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
TODO: it need log(n) solution.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	///running time:O(nlogn)
    int findMin(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[0];
    }

    //runing time; O(n)
    int findMin2(vector<int> &num) {
        int size=num.size();
        int min=num[0];
        int i=0;
        while(i<size){
        	if(num[i]<min){
        		min=num[i];
        		break;
        	}
        	i++;
        }
        return min;
    }
};



int main(){

	return 0
}