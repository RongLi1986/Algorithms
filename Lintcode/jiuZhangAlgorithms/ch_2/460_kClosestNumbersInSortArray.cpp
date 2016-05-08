/*
Given a target number, a non-negative integer k and an integer array A sorted in ascending order, 
find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. 
Otherwise, sorted in ascending order by number if the difference is same.
*/

#include <iostream>
using namespace std;

/*
binary search find cloest number with target, put it into res vector
then put k numbers which from its left and right 
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param target an integer
     * @param k a non-negative integer
     * @return an integer array
     */
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        // Write your code here
        vector<int> res;
        
        //corner case 
        if(A.empty() || k==0){
            return res;
        }
        
        int left = 0;
        int right = A.size()-1;
        int mid; 
        while(left+1<right){
            mid = (left + right) /2;
            if(A[mid] == target){
                break;
            }else if(A[mid] < target){
                left =mid;
            }else{
                right = mid;
            }
        }
        
        int min = INT_MAX;
        int min_Index;
        if(abs(target-A[mid])<min){
            min=abs(target-A[mid]);
            min_Index = mid;
        }
        
        if(mid==0){
            if(abs(target-A[mid+1])<min){
                min = abs(target-A[mid+1]);
                min_Index = mid+1;
            }
        }else if(mid==A.size()-1){
            if(abs(target-A[mid-1])<min){
                min = abs(target-A[min-1]);
                min_Index = mid-1;
            }
        }else{
            if(abs(target-A[mid+1])<min){
                min = abs(target-A[mid+1]);
                min_Index = mid+1;
            }
            
            if(abs(target-A[mid-1])<=min){
                min = abs(target-A[mid-1]);
                min_Index = mid-1;
            }
        }
        
        //firstly put min_Index into res vector
        res.push_back(A[min_Index]);
        
        int i = min_Index - 1;
        int j = min_Index + 1;
        int count = 1;  //count k-1 
        while(i>=0 && j<=A.size() && count < k){
            if(abs(A[i]-target)>abs(A[j]-target)){
                res.push_back(A[j]);
                j++;
            }else{
                res.push_back(A[i]);
                i--;
            }
            count++;
        }
        
        while(i>=0 && count < k){
            res.push_back(A[i]);
            i--;
            count++;
        }
        
        while(j>=0 && count < k){
            res.push_back(A[j]);
            j++;
            count++;
        }
        
        return res;
    }
};

int main(){

	return 0;
}