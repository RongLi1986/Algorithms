# 1738. Find Kth Largest XOR Coordinate Value

## Question link
(https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/)

## Question Description

You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

Example 1:

Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
Example 2:

Input: matrix = [[5,2],[1,6]], k = 2
Output: 5
Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
Example 3:

Input: matrix = [[5,2],[1,6]], k = 3
Output: 4
Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
Example 4:

Input: matrix = [[5,2],[1,6]], k = 4
Output: 0
Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, which is the 4th largest value.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n

```c++
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                // Caculate the xor result base on preXOR 
                int a = i != 0 ? matrix[i-1][j] : 0;
                int b = j != 0 ? matrix[i][j-1] : 0;
                int c = (i == 0 || j == 0) ? 0 : matrix[i-1][j-1];
                
                if(i != 0 || j != 0){
                    matrix[i][j] = a ^ b ^ c ^ matrix[i][j];
                }
                
                // Push and maintain the priority queue
                pq.push(matrix[i][j]);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};
```