/*
Median of two Sorted Arrays

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.
*/

/*

*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        if(A.empty() && B.empty())
            return 0.0;
        vector<double> C(A.size()+B.size(), 0);
        
        for(int i=0;i<A.size();i++){
            C[i]= (double) A[i];
        }
        
        for(int i=0;i<B.size();i++){
            C[A.size() + i]= (double) B[i];
        }
        
        
        sort(C.begin(), C.end());
        
        if(C.size() % 2 ==0){
            return (C[C.size()/2] +C[C.size()/2-1])/2;
        }else{
            return C[C.size()/2];
        }
    }
};