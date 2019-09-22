/*******************************************************
Description
中文
English
Find the kth smallest number in a row and column sorted matrix.

Each row and each column of the matrix is incremental.

Example
Example 1:

Input:
[
  [1 ,5 ,7],
  [3 ,7 ,8],
  [4 ,8 ,9],
]
k = 4
Output: 5
Example 2:

Input:
[
  [1, 2],
  [3, 4]
]
k = 3
Output: 3
********************************************************/


/*
解题思路：
O(klogN)
*/ 

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        if(matrix.empty() || matrix[0].empty()) return -1;
        if(matrix.size() * matrix[0].size() < k) return -1;
        
        //define priority_queue with custom comparator
        auto comp = [] (pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) -> bool { return a.first > b.first; };
        priority_queue<pair<int, pair<int, int> >,
                vector<pair<int, pair<int, int> >>, 
                decltype(comp) > pq (comp);
        
        //visitor map
        vector<vector<int>> vistor_map(matrix.size(), vector<int>(matrix[0].size(), 0)); 
        
        pq.push({matrix[0][0], {0,0}});
        vistor_map[0][0] = 1;
        
        //pop k-1 item
        for(int i = 0; i < k - 1; i++){
            auto item = pq.top();
            pq.pop();
            int x = item.second.first;
            int y = item.second.second;
            //cout<<matrix[x][y]<<endl;
            if(x + 1 >= 0 && x + 1 < matrix.size() && vistor_map[x + 1][y] == 0){
                pq.push({matrix[x + 1][y], {x + 1,y}});
                vistor_map[x + 1][y] = 1;
            }
            if(y + 1 >= 0 && y + 1 < matrix[0].size() && vistor_map[x][y + 1] == 0){
                pq.push({matrix[x][y + 1], {x,y + 1}});
                vistor_map[x][y + 1] = 1;
            }
        }
        
        return pq.top().first;
    }
};