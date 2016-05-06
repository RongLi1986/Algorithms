/*
Find any position of a target number in a sorted array. Return -1 if target does not exist.
*/

#include <iostream>
using namespace std;

/*
binary search
O(lgn)
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        if(A.empty()) return -1;
        int left =0;
        int right =A.size()-1;
        
        while(left+1<right){
            int mid =  (left + right)/2;
            
            if(A[mid]==target){
                return mid;
            }else if(A[mid]<target){
                left = mid;
            }else{
                right = mid;
            }
            //cout<<left<<" "<<mid<<" "<<right<<endl;
        }
        
        return -1;
    }
};


int main(){

	return 0;
}