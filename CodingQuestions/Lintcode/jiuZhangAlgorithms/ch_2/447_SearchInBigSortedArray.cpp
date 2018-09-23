/*
Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++). Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.
*/

/*
binary search find table's length
then, binary search in this table.
*/


#include <iostream>
using namespace std;

/**
 * Definition of ArrayReader:
 * 
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index, 
 *          // return -1 if index does not exist.
 *     }
 * };
 */

class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        // write your code here
        if(reader==NULL) return -1;
        
        //step 1. find end range
        int end=1;
        while(reader->get(end)!=-1){
            end=end*2;
        }
        

        //conform right
        int left=0;
        int right=end;
        while(left<=right){
            int mid=(left+right)/2;
            if(reader->get(mid)==-1){
                right=mid-1;
            }
            else
                left=mid+1;
        }
        
        left=0;
        
        while(left+1<right){
            int mid=(left+right)/2;
    
            if(reader->get(mid)<target)
                left=mid;
            else
                right=mid;
        }

        if(reader->get(right)==target)
            return right;
        else if(reader->get(left)==target)
            return left;
        
        return -1;
    }
};


int main(){

	return 0;
}