/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

 Notice

You may assume no duplicate exists in the array.
*/

/*
before use binary search, it need to compare num[left] and num[right](check whether left and right in rotated array)
if not, skrink right to mid -1;
if yes. check num[mid]:
if num[mid] in left side (large number), change left to mid +1 
if num[mid] in right side (small number), change right to mid -1; 
*/

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.empty()) return 0;
        int min=INT_MAX;
        int left = 0;
        int right = num.size()-1;
        
        while(left<=right){
            //cout<<left<<" "<<right<<endl;
            
            int mid=(left+right)/2;
            //cout<<num[left]<<" "<<num[mid]<<" "<<num[right]<<endl;
            
            if(num[mid] < min){
                min = num[mid];
            }
            
            if(num[left] <= num[right]){ //no rotate
                right = mid-1;
            }else{
                if(num[mid]>=num[left]){
                    left = mid + 1;
                }
                
                if(num[mid]<=num[right]){
                    right = mid -1;
                }
            }
        }
        
        return min;
    }
};

int main(){

	return 0;
}