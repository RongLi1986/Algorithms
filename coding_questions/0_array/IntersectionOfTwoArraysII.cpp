/*
Given two arrays, write a function to compute their intersection.
Notice
Each element in the result should appear as many times as it shows in both arrays. The result can be in any order.
Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Challenge
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
solution:

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
            unordered_map<int, int> mapA;
            unordered_map<int, int> mapB;
            vector<int> ret;

            for(int i = 0 ; i < A.size(); i++){
                if(mapA.find(A[i]) == mapA.end()){
                    mapA[A[i]] = 0;
                }
                mapA[A[i]]++;
            }
            
            for(int i = 0; i < B.size(); i++){
                if(mapB.find(B[i]) == mapB.end()){
                    mapB[B[i]] = 0;
                }
                mapB[B[i]]++;
            }

            for(auto i = mapA.begin(); i != mapA.end(); i++){
                if(mapB.find(i->first)!= mapB.end()){
                    for(int j = 0; j < min(i->second, mapB[i->first]); j++){
                        ret.push_back(i->first);
                    }
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
    vector<int> t1 = {1,4,4,8,9};
    vector<int> t2 = {4,4,8,8,7};
    vector<int> expect = {4,4,8};
    vector<int> r = s->func(t1, t2);  
    cout << "expect is: " << DumpVector(expect) << ", result is: " << DumpVector(r) << endl;

    cout << endl;
    cout << "test case 2" << endl;
    t1 = {1,2,3};
    t2 = {7,10,14,17};
    expect = {};
    r = s->func(t1, t2);  
    cout << "expect is: " << DumpVector(expect) << ", result is: " << DumpVector(r) << endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



