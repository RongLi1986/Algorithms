# 59. Spiral Matrix II

## Question link
(https://leetcode.com/problems/spiral-matrix-ii/description/)

## Question Description

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

## 解题思路

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        vector<vector<int>> out(n, vector<int>(n, 0));
        int u = 0, d = n - 1, l = 0, r = n - 1, k = 1;
        
        while (true) {
            // up
            for (int col = l; col <= r; col++) out[u][col] = k++;
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) out[row][r] = k++; 
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) out[d][col] = k++; 
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) out[row][l] = k++; 
            if (++l > r) break;
        }
        
        return out;
    }
};
```