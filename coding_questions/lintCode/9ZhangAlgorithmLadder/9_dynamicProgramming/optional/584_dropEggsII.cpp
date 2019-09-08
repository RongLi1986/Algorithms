/*
Drop Eggs II

There is a building of n floors. If an egg drops from the k th floor or above, 
it will break. If it's dropped from any floor below, it will not break.

You're given m eggs, Find k while minimize the number of drops for the worst case. 
Return the number of drops in the worst case.

Have you met this question in a real interview? Yes
Example
Given m = 2, n = 100 return 14
Given m = 2, n = 36 return 8
*/

class Solution {
public:
    /**
     * @param m the number of eggs
     * @param n the umber of floors
     * @return the number of drops in the worst case
     */
    int dropEggs2(int n, int k) {
        // Write your code here
        int eggFloor[n+1][k+1];
        int res;
        
        for(int i=1;i<=n;i++){
            eggFloor[i][1] = 1;
            eggFloor[i][0] = 0;
        }
        
        for(int j = 1; j<=k;j++){
            eggFloor[1][j] = j;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                eggFloor[i][j] = INT_MAX;
                for(int x =1;x<=j;x++){
                    res = 1 + max(eggFloor[i-1][x-1],eggFloor[i][j-x]);
                    if(res<eggFloor[i][j]){
                        eggFloor[i][j] = res;
                    }
                }
            }
        }
        
        return eggFloor[n][k];
    }
};