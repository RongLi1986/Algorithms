/*
Backpack II

Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
*/

/*
DP:
f(i,j): for A[0:i], max numbers of item could be placed in backpack of value j.
intial: f(0,j) == (A[0] > j +1 ) ? 0 : V[0];
        f(i,0) == (A[i] > 1) ? 0: V[i];
function: 
        //for A[i] should we put it into backpack?
        // 1. backpack must have enough space  ==> j+1-A[i]>=0
        // 2. could get a larger value ==> V[i]+f[i+1][j-A[i]] > f[i+1][j]
        f(i,j) == f(i+1,j)             //
               == f(i+1,j-A[i]) + V[i] // V[i]+f[i+1][j-A[i]] > f[i+1][j]

result: f[0][m-1]
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
         //each time copy row i result to row i+1
        //so it only need two rows' vector
        vector<vector<int>> map(2, vector<int> (m, 0));
        
        for(int j=0;j<m;j++){
            if(A[A.size()-1]>j+1)
                map[1][j] = 0;
            else
                map[1][j] = V[V.size()-1];
        }
        
        for(int i=0;i<map.size();i++){
            if(A[i]>0+1)
                map[i][0] = 0;
            else
                map[i][0] = V[i];
        }
        
        for(int i=A.size()-2; i>=0; i--){
            for(int j=1; j<m; j++){
                if(j+1-A[i]<0){
                    map[0][j] = map[1][j];
                }else{
                    //if(i==2 && j==9)
                    //  cout<<map[i+1][j-A[i]]<<endl;
                    if(V[i]+map[1][j-A[i]]>map[1][j]){
                        map[0][j]= V[i]+map[1][j-A[i]];
                    }else{
                        map[0][j]=map[1][j];
                    }
                }
            }
            
            //copy map[0] to map [1]
            for(int k=0;k<m;k++){
                map[1][k]=map[0][k];
            }
        }
    
        /*
        for(int i=0;i<A.size();i++){
            for(int j=0;j<m;j++){
                cout<<map[i][j]<<" ";
            }
             cout<<endl;
        }
        */

        return map[0][m-1];
    }
};