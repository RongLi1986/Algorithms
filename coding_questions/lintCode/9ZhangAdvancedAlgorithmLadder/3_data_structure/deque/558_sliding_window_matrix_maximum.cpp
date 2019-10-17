/*
Sliding Window Matrix Maximum 558

Question
Given an array of n m matrix, and a moving matrix window (size k k), 
move the window from top left to botton right at each iteration, 
find the maximum sum of the elements inside the window at each moving. Return 0 if the answer does not exist.

Example
For matrix
[ [1, 5, 3], [3, 2, 1], [4, 1, 9], ]
The moving window size k = 2.
return 13.

At first the window is at the start of the array like this
[ [|1, 5|, 3], [|3, 2|, 1], [4, 1, 9], ]
,get the sum 11;

then the window move one step forward.
[ [1, |5, 3|], [3, |2, 1|], [4, 1, 9], ]
,get the sum 11;

then the window move one step forward again.
[ [1, 5, 3], [|3, 2|, 1], [|4, 1|, 9], ]
,get the sum 10;

then the window move one step forward again.
[ [1, 5, 3], [3, |2, 1|], [4, |1, 9|], ] ,get the sum 13;
SO finally, get the maximum from all the sum which is 13.

Challenge
O(n^2) time.
*/

/*
Sliding Window Maximum + Sub Array Sum
*/

class Solution {
    /**
     * @param matrix an integer array of n * m matrix
     * @param k an integer
     * @return the maximum number
     */
public:
    int maxSlidingWindow2(vector<vector<int> > matrix, int k) {
        // Write your code here
        if(matrix == null || matrix.size() == 0 || matrix[0].size() == 0 || k > matrix.size() || k > matrix[0].size()){
            return -1;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > sum(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++){
            sum[i][0] = 0;
        }

        for(int j = 1; j <= m; j++){
            sum[0][j] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = matrix[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] -sum[i - 1][j - 1];
            }
        }

        int retval = INT_MIN;
        for(int i = k; i <= n; i++){
            for(int j = k; j <= m; j++){
                int temp = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
                retval = max(retval, temp);
            }
        }

        return max;
    }
};