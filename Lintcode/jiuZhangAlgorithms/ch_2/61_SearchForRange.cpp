/*
Given a sorted array of n integers, find the starting and ending position of a given target value.

If the target is not found in the array, return [-1, -1].
*/

/*
binary search find first target and last target
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    //O(n)
    vector<int> searchRange1(vector<int> &A, int target) {
        // write your code here
        int flag=0;
        vector<int> res;
        for(int i=0;i<A.size();i++){
            if(A[i]==target && flag==0){
                flag=1;
                res.push_back(i);
            }
            
            if(A[i]!=target && flag ==1){
                flag =0;
                res.push_back(i-1);
                return res;
            }
                
        }
        
        if(flag==1){
            res.push_back(A.size()-1);
            return res;
        }
        
        vector<int> empty(2,-1);
        return empty;
    }
    
    //O(lgn)
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int flag=0;
        vector<int> res;
        int first=binarySearchFirst(A , target);
        int last=binarySearchLast(A , target);
        
        res.push_back(first);
        res.push_back(last);
        
        return res;
    }
    
    int binarySearchLast(vector<int> &array, int target) {
        // write your code here
        if(array.empty()) return -1;
        if(array[array.size()-1]==target) return array.size()-1;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid]<=target){
                left=mid;
            }else {
                right=mid;
            }
        }
        
        if(target==array[left]){
            return left;
        }
        
        return -1;
    }
    
    
    int binarySearchFirst(vector<int> &array, int target) {
        // write your code here
        if(array.empty()) return -1;
        if(array[0]==target) return 0;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid]<target){
                left=mid;
            }else {
                right=mid;
            }
        }
        
        if(target==array[right]){
            return right;
        }
        
        return -1;
    }
};

int main(){

	return 0;
}