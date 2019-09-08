/*
Merge two given sorted integer array A and B into a new sorted integer array.

Have you met this question in a real interview? Yes
Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]
*/

/*
merge
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> res;
        
        int indexA = 0;
        int indexB = 0;
        
        while(indexA<A.size() && indexB<B.size()){
            if(A[indexA] > B[indexB]){
                res.push_back(B[indexB]);
                indexB++;
            }else if(A[indexA] <= B[indexB]){
                res.push_back(A[indexA]);
                indexA++;
            }
        }
        
        while(indexA<A.size()){
            res.push_back(A[indexA]);
            indexA++;
        }
        
        while(indexB<B.size()){
            res.push_back(B[indexB]);
            indexB++;
        }
        
        return res;
    }
};