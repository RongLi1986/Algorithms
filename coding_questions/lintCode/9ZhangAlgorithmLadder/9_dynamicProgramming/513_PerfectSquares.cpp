/*
Perfect Squares

Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Have you met this question in a real interview? Yes
Example
Given n = 12, return 3 because 12 = 4 + 4 + 4
Given n = 13, return 2 because 13 = 4 + 9

Tags 

*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int> map(n+1,INT_MAX);
        
        for(int i=1;i<n+1;i++){
            if(isSquares(i)){
                map[i]=1;
            }else{
                int j = 1;
                while(j*j<i){
                    map[i] = min(1 + map[i-j*j], map[i]);
                    j++;
                }
            }
        }
        
        /*
        for(int j=0;j<map.size();j++){
            cout<<map[j]<<" ";
        }
        cout<<endl;
        */
        
        return map[n];
        
    }
    
    bool isSquares(int n){
        int tmp =sqrt(n);
        return (tmp*tmp)==n;
    }
};