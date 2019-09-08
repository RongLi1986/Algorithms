/*
Sort Colors II

Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

 Notice

You are not suppose to use the library's sort function for this problem.

Have you met this question in a real interview? Yes
Example
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].
*/

/*
do it in place
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        sort(colors.begin(), colors.end());
    }
};