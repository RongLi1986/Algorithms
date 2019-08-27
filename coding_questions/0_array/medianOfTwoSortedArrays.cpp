/*
Median of Two Sorted Arrays
http://www.lintcode.com/en/problem/median-of-two-sorted-arrays/

Question
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.
Given A=[1,2,3] and B=[4,5], the median is 3.
*/

/*
solution:
对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1], 
若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2; 

如果我们可以在两个数列中求出第K小的元素，便可以解决该问题; 
不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素; 
取A[k / 2] B[k / 2] 比较; 
如果 A[k / 2] > B[k / 2] 
那么，所求的元素必然不在B的前k / 2个元素中(证明反证法); 反之，必然不在A的前k / 2个元素中，
于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的; k - k / 2小元素，

于是得到了数据规模变小的同类问题，递归解决; 

如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好.
*/

#include "../include/header.cpp"

class Solution {
    public:
        /**
         * @param A: An integer array.
         * @param B: An integer array.
         * @return: a double whose format is *.5 or *.0
         */
        double func(vector<int> A, vector<int> B) {
            int totalLength = A.size() + B.size();
            if (totalLength % 2 == 1) {
                return findKth(A, 0, B, 0, totalLength / 2 + 1);
            }
            return (findKth(A, 0, B, 0, totalLength / 2) + findKth(A, 0, B, 0, totalLength / 2 + 1)) / 2.0;
        }

        /**
         * @param A: An integer array.
         * @param idxA: An integer array A idx.
         * @param B: An integer array.
         * @param idxB: An integer array B idx.
         * @param k: find k th idx.
         * @return: a double whose format is *.5 or *.0
         */
        int findKth(vector<int> A, int idxA, vector<int> B, int idxB, int k){

            if (idxA >= A.size()) {
                return B[idxB + k - 1];
            }
            if (idxB >= B.size()) {
                return A[idxA + k - 1];
            }

            if (k == 1) {
                return min(A[idxA], B[idxB]);
            }

            int A_key = idxA + k / 2 - 1 < A.size() ? A[idxA + k / 2 - 1] : INT_MAX;
            int B_key = idxB + k / 2 - 1 < B.size() ? B[idxB + k / 2 - 1] : INT_MAX;

            if (A_key < B_key) {
                return findKth(A, idxA + k / 2, B, idxB, k - k / 2);
            } else {
                return findKth(A, idxA, B, idxB + k / 2, k - k / 2);
            }
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "begin testing:...."<<endl; 
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    vector<int> t1 = {1,4,8,12,16,22};
    vector<int> t2 = {2,3,7,10,14,17,19,25};
    double expect = 11.0;
    double r = s->func(t1, t2);  //expect 11.0
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "test case 2" << endl;
    t1 = {1,2,3};
    t2 = {7,10,14,17};
    expect = 7.0;
    r = s->func(t1, t2);  //expect 7.0
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "test case 3" << endl;
    t1 = {};
    t2 = {7,10,14,17};
    expect = 12.0;
    r = s->func(t1, t2);  //expect 12.0
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "test case 4" << endl;
    t1 = {1,2,3,4,5};
    t2 = {};
    expect = 3.0;
    r = s->func(t1, t2);  //expect 3.0
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



