/*
Binary Search

29% Accepted
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Have you met this question in a real interview? Yes
Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/

/*
basic binary search
but when it find target number,
it need to check left side repeated number
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int left=0;
        int right=array.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(array[mid]==target){
                //kill repeat numbers
                while(mid!=0&&array[mid]==array[mid-1])
                    mid--;
                return mid;
            }
            else if(array[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return -1;
    }
};



int main(){
	vector<int> numbers;

	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	

	int target=6;

	Solution s;
	s.twoSum(numbers,target);

	return 0;
}