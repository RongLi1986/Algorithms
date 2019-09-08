/*
Triangle Count

Given an array of integers, how many three numbers can be found in the array, 
so that we can build an triangle whose three edges length is the three numbers 
that we find?

Have you met this question in a real interview? Yes
Example
Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]
Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
*/

/*

*/

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &s) {
        // write your code here
        sort(s.begin(), s.end());
        
        int ans = 0;
        for(int i = s.size()-1;i>=0;i--){
            int left = 0;
            int right = i-1;
            while(left<right){
                if(s[left]+s[right]<=s[i] ){
                    left++;
                }else{
                    ans+=(right-left);
                    right--;
                }
            }
        }
        
        return ans;
    }
};