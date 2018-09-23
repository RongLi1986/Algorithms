/*
Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
binary search. 
need to check which side has target and num[mid].
*/

#include <iostream>
using namespace std;
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &num, int target) {
        // write your code here
        int left = 0;
        int right = num.size()-1;
        
        while(left<=right){
            
            int mid = (left + right)/2;
            //cout<<mid<<endl;
            if(num[mid] == target){
                return mid;
            }
            
            if(num[left] <= num[right]){ //no rotate
                if(num[mid]>target){
                    right=mid-1;
                }else if(num[mid]<target){
                    left=mid+1;
                }
            }else{ //rotate axis
                /*
                check target and mid in which side:
                */
                if(target<=num[right]){ //target in pivot right side
                    if(num[mid]>num[right]){ //mid in pivot left side
                        left=mid+1;          //kill left
                    }else if(num[mid]<num[left]){ //mid in pivot right side
                        /* 
                        if target and mid in same side
                        then compare them.
                        */
                        if(num[mid]>target){
                            right=mid-1;
                        }else if(num[mid]<target){
                            left=mid+1;
                        }
                    }
                }else if(target>=num[left]){  //target in pivot left side
                    if(num[mid]<num[right]){  //mid in pivot right side
                        right=mid-1;          //kill right
                    }else if(num[mid]>num[left]){  //mid in pivot left side
                        /* same side cases*/
                        if(num[mid]>target){
                            right=mid-1;
                        }else if(num[mid]<target){
                            left=mid+1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

int main(){

	return 0;
}