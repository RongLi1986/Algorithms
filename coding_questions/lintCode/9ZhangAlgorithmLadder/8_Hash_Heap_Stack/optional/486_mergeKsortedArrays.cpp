/*
Given k sorted integer arrays, merge them into one sorted array.

Example
Given 3 sorted arrays:

[
  [1, 3, 5, 7],
  [2, 4, 6],
  [0, 8, 9, 10, 11]
]
return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
*/


/*
use a priority_queue, put all int into it running time (nlg(n))
*/

class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        // Write your code here
        priority_queue<int, vector<int>, std::greater<int> > pq;
        vector<int> res;
        
        for(int i=0;i<arrays.size();i++){
            for(int j=0;j<arrays[i].size();j++){
                pq.push(arrays[i][j]);       
            }
        }
        
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            res.push_back(top);
        }
        
        return res;
        
    }
};