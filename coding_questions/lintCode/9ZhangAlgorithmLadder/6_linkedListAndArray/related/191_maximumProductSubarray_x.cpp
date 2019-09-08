/*
Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Have you met this question in a real interview? Yes
Example
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*/

/*

*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    
    //DP O(n^2)  not acceptable 
    /*
    int maxProduct(vector<int>& nums) {
        // write your code here
        vector<vector<int> > map(nums.size(), vector<int>(nums.size(), 0));
        
        int max = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            map[i][i] = nums[i];
            if(map[i][i] > max)
                    max = map[i][i];
        }
        
        for(int i=0;i<map.size();i++){
            for(int j=i+1;j<map[i].size();j++){
                map[i][j] = nums[j] * map[i][j-1];
                if(map[i][j] > max)
                    max = map[i][j];
            }
        }
    
        return max;
    }
    */
    
    /*
    So, given a whole scan , how to find the maximum product?
    Note that, we need to consider two cases:
    (1) negative numbers
              Store the minimum product to handle the case that new element < 0. Because if current element < 0, the product of two negative numbers (new element, and minimum product before the new element) become positive.
    (2) zeros
            When meets zero, current max and min product become 0, new search is needed from the next element.
    
    Therefore,  we can write down to function to store both + and - products:
    
    max_product = max{A[i]*min_product (when A[i]<0),  A[i]*max_product (when A[i]>0),  A[i] (when 0 occurs before A[i]) }.
    
    min_product = min{A[i]*min_product,  A[i]*max_product,  A[i] }.
    
    Because current sequence might start from any element, 
    to get the final result, we also need to store the max product after 
    each iteration "res = max(res, maxp);".
    */
    
    int maxProduct(vector<int>& A) {
        // write your code here
        int res = A[0];
        int maxp = A[0];
        int minp = A[0];
        for (int i=1;i<A.size();i++){
            int tmpmax = maxp;
            int tmpmin = minp;
            maxp = max(max(tmpmax*A[i],tmpmin*A[i]),A[i]);
            minp = min(min(tmpmax*A[i],tmpmin*A[i]),A[i]);
            res = max(maxp,res);
        }
        return res;
    }
};

