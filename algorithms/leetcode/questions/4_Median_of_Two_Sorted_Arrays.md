# 4. Median of Two Sorted Arrays

## Question link
(https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

## Question Description
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

## 解题思路
对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1], 若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2; 
如果我们可以在两个数列中求出第K小的元素，便可以解决该问题; 不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素; 
取A[k / 2] B[k / 2] 比较; 如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法); 
反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的; k - k / 2小元素，
于是得到了数据规模变小的同类问题，递归解决; 如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好

Time complexity: O(log(min(m,n))).
Space complexity: O(1)

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int> A,vector<int> B) {
        int m = A.size();
        int n = B.size();

        int *array_A = new int[m];
        int *array_B = new int[n];

        for(int i=0;i<m;i++){
            array_A[i] = A[i];
        }

        for(int i=0;i<n;i++){
            array_B[i] = B[i];
        }

        if((n+m)%2 ==0)  
        {  
            return (findMedian(array_A, m, array_B, n, (m+n)/2) + findMedian(array_A,m,array_B,n, (m+n)/2+1))/2.0;  
        }  
        else  
            return findMedian(array_A, m, array_B,  n, (m+n)/2+1);
    }  

    int findMedian(int a[], int m, int b[],  int n, int k){
        //cout<<m<<" "<<n<<" "<<k<<endl;
        if (m <= 0) return b[k-1];  
        if (n <= 0) return a[k-1];  
        if (k == 1) return min(a[0], b[0]);   
        
        
        int A_key = k / 2 - 1 < m ? a[k / 2 - 1] : INT_MAX;
        int B_key = k / 2 - 1 < n ? b[k / 2 - 1] : INT_MAX;
        //cout<<A_key<<" "<<B_key<<" "<<endl;
        
        if (A_key< B_key)  
        {  
            return findMedian(a + k/2, m - (k/2), b, n, k - (k/2));  
        }  
        else  
        {  
            return findMedian( a, m, b + k/2, n - (k/2),k - (k/2));  
        }  
    }
};
```