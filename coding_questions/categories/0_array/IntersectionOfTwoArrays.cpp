/*
Question
Given two arrays, write a function to compute their intersection.
Each element in the result must be unique. The result can be in any order.
Example Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/

/*
solution:
是利用HashMap，循环nums1[]一遍，记录下nums1[]中出现的数字，再对nums2[]做循环，
如果在HashMap中出现过，则记录到最后的结果中。
*/

#include "../include/header.hpp"

class Solution {
    public:
        /**
         * @param nums1 an integer array
         * @param nums2 an integer array
         * @return an integer array
         */
        vector<int> func(vector<int> A, vector<int> B) {
            unordered_set<int> set_A;
            unordered_set<int> insert_map;
            vector<int> ret;

            for(int i = 0 ; i < A.size(); i++){
                set_A.insert(A[i]);
            }
            
            for(int i = 0; i < B.size(); i++){
                if(set_A.find(B[i]) != set_A.end() && insert_map.find(B[i]) == insert_map.end()){
                    ret.push_back(B[i]);
                    insert_map.insert(B[i]);
                }
            }

            return ret;
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    vector<int> t1 = {1,4,8,9};
    vector<int> t2 = {4,8,7};
    vector<int> expect = {8};
    vector<int> r = s->func(t1, t2);  //expect 11.0
    cout << "expect is: " << DumpVector(expect) << ", result is: " << DumpVector(r) << endl;

    cout << "test case 2" << endl;
    t1 = {1,2,3};
    t2 = {7,10,14,17};
    expect = {};
    r = s->func(t1, t2);  //expect 7.0
    cout << "expect is: " << DumpVector(expect) << ", result is: " << DumpVector(r) << endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



