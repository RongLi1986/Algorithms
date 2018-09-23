/***************************************************************
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

***************************************************************/
#include <iostream>

using namespace std;


/* this way running time is O(n)
merge two array and find their median
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int> A,vector<int> B) {
        int m=A.size();
        int n=B.size();
        int* C=new int[m+n];
        int i=0;
        int j=0;
        int k=0;

        //merge array
        while(i<m+n && j<m && k<n){     
            if(A[j]<B[k]){
                C[i]=A[j];
                i++;
                j++;
            }else{
                C[i]=B[k];
                i++;
                k++;
            }
        }

        while(j<m){
                C[i]=A[j];
                i++;
                j++;
        }

        while(k<n){
            C[i]=B[k];
            i++;
            k++;
        }
    
        if((m+n)%2==0){  //find median and cast to double 
            int medianIndex=(m+n)/2;
            double output=(static_cast<double>(C[medianIndex])+static_cast<double>(C[medianIndex-1]))/2;
            return output;
            
        }else{
            int medianIndex=(m+n)/2;
            return static_cast<double>(C[medianIndex]);
        } 
    }
};


//O(lg(m+n))  come from GeekforGeek
/*
1) Calculate the medians m1 and m2 of the input arrays ar1[] 
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one    
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays 
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2


*/
class Solution {
public:
    double findMedianSortedArrays(vector<int> A,vector<int> B) {
        int m=A.size();
        int n=B.size();

        int *array_A=new int[m];
        int *array_B=new int[n];

        for(int i=0;i<m;i++){
            array_A[i]=A[i];
        }

        for(int i=0;i<n;i++){
            array_B[i]=B[i];
        }

        if((n+m)%2 ==0)  
        {  
            return (findMedian(array_A, m, array_B, n, (m+n)/2) + findMedian(array_A,m,array_B,n, (m+n)/2+1))/2.0;  
        }  
        else  
            return findMedian(array_A, m, array_B,  n, (m+n)/2+1);        
    }  



    //O(lg(m+n))
    int findMedian(int a[], int n, int b[],  int m, int k){
        if (n <= 0) return b[k-1];  
        if (m <= 0) return a[k-1];  
        if (k <= 1) return min(a[0], b[0]);   
        if (b[m/2] >= a[n/2])  
        {  
             if ((n/2 + 1 + m/2) >= k)  
                  return findMedian(a, n, b, m/2, k);  
             else  
                  return findMedian(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));  
        }  
        else  
        {  
             if ((m/2 + 1 + n/2) >= k)  
                  return findMedian( a, n/2,b, m, k);  
             else  
                  return findMedian( a, n, b + m/2 + 1, m - (m/2 + 1),k - (m/2 + 1));  
        }  
    }
};






