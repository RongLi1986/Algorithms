/*
two intervels with same sum.
Question
give an array, find two non-overlap intervels with same value K.

return mininum length of two intervels 


Example:
A = [1,2,2,3,1,4] K=5

return 4 ([2,3] and [1,4])
*/

/*
Solution:

*/

#include "../include/header.hpp"

class Solution {

    public:
        /**
         * @param vector<int> , integer 
         * @return integer
         */
        int func(vector<int> A, int K) {
            vector<int> l(A.size(), INT_MAX);
            vector<int> r(A.size(), INT_MAX);
            unordered_map<int, int> hash;
            
            int prefixSum = 0;
            int minLen = INT_MAX;
            hash[0] = -1;
            for(int i = 0;i<A.size();i++){
                prefixSum += A[i];
                if(hash.find(prefixSum - K) != hash.end()){
                    int len = i - hash[prefixSum - K];
                    minLen = min(len, minLen);
                    l[i] = minLen;
                }else{
                    if(i==0) {
                        l[i] = INT_MAX;
                    }else{
                        l[i] = min(l[i-1], l[i]);
                    }
                }

                if(hash.find(prefixSum)!=hash.end()){
                    hash[prefixSum] = max(i, hash[prefixSum]);
                }else{
                    hash[prefixSum] = i;
                }
            }
            
            prefixSum = 0;
            hash.clear();
            hash[0] = A.size() + 1;
            for(int i = A.size()-2;i>=0;i--){
                prefixSum += A[i+1];
                if(hash.find(prefixSum - K) != hash.end()){
                    int len = hash[prefixSum - K] - i;
                    minLen = min(len, minLen);
                    r[i] = minLen;
                }else{
                    r[i] = min(r[i+1], r[i]);
                }

                if(hash.find(prefixSum)!=hash.end()){
                    hash[prefixSum] = min(i, hash[prefixSum]);
                }else{
                    hash[prefixSum] = i;
                }
            }

            // for(int i=0;i<l.size();i++){
            //     cout<<l[i]<<" ";
            // }
            // cout<<endl;

            // for(int i=0;i<r.size();i++){
            //     cout<<r[i]<<" ";
            // }
            // cout<<endl;

            int retval = INT_MAX;
            for(int i=0;i<A.size()-1;i++){
                if(l[i] != INT_MAX and r[i] != INT_MAX){
                    retval = min(retval, l[i]+r[i]);
                }
            }
            cout<<retval<<endl;
            return retval;
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    vector<int> A = {1,2,2,3,1,4};
    int K = 5;
    s->func(A, K);

    cout << "test case 2" << endl;
    A = {2,3,3,2,3,2,3,8};
    K = 8;
    s->func(A, K);

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}