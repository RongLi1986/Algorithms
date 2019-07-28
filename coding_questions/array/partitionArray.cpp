/*
Partition Array
Sort, Array
Medium
Problem
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.
Notice
You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
If all elements in nums are smaller than k, then return nums.length
*/

/*
solution: O(n)
设置一个offset值，每次将 <k 的值与offset位置上的值交换位置，然后offset++。因为不需要担心顺序，所以可以无论exchange的数是否小于k，
最后所有左边的数都会小于k 
*/
#include "../include/header.cpp"

class Solution {
    public:
        /**
         * @param nums: The integer array you should partition
         * @param k: An integer
         * @return: The index after partition
         */
        int partitionArray(vector<int> nums, int k) {
            // write your code here
            if (nums.size() == 0) {
                return 0;
            }

            int offset = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < k) {
                    //swap
                    int temp = nums[i];
                    nums[i] = nums[offset]; 
                    nums[offset] = temp;
                    offset ++; 
                }
            }

            return offset; 
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "begin testing:...."<<endl; 
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    vector<int> t1 = {1,14,6,2,3,8,11,2,2};
    int expect = 5;
    int r = s->partitionArray(t1, 6);  //expect 5
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "test case 2" << endl;
    vector<int> t2 = {1,14,6,2,3,8,11,2,2};
    expect = 0;
    r = s->partitionArray(t1, 0);  //expect 0
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "test case 3" << endl;
    vector<int> t3 = {1,14,6,2,3,8,11,2,2};
    expect = 7;
    r = s->partitionArray(t1, 100);  //expect 7
    cout << "expect is: " << expect << ", result is: " << r <<  endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



