/*
Backpack

Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.
*/


/*
DP:
f(i,j): for A[0:i], max numbers of item could be placed in backpack of value j.
intial: f(0,j) == (A[0] > j +1 ) ? 0 : A[0];
        f(i,0) == (A[i] > 1) ? 0: A[i];
function: 
        //for A[i] should we put it into backpack?
        // 1. backpack must have enough space  ==> j+1-A[i]>=0
        // 2. A[i]+f[i+1][j-A[i]] > f[i+1][j]
        f(i,j) == f(i+1,j)             //
               == f(i+1,j-A[i]) + A[i] // A[i]+f[i+1][j-A[i]] > f[i+1][j]

result: f[0][m-1]
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        //use normal vector
        
        /*
        vector<vector<int>> map(A.size(), vector<int> (m, 0));
        
        for(int j=0;j<m;j++){
            if(A[A.size()-1]>j+1)
                map[A.size()-1][j] = 0;
            else
                map[A.size()-1][j] = A[A.size()-1];
        }
        
        for(int i=0;i<A.size();i++){
            if(A[i]>1)
                map[i][0] = 0;
            else
                map[i][0] = A[i];
        }
        
        for(int i=A.size()-2; i>=0; i--){
            for(int j=1; j<m; j++){
                
                if(j+1-A[i]<0){
                    map[i][j] = map[i+1][j];
                }else{
                    
                    //if(i==2&&j==9)
                       // cout<<map[i+1][j-A[i]]<<endl;
                        
                    if(A[i]+map[i+1][j-A[i]]>map[i+1][j]){
                        map[i][j]= A[i]+map[i+1][j-A[i]];
                    }else{
                        map[i][j]=map[i+1][j];
                    }
                }
            }
        }
        */
        
        //each time copy row i result to row i+1
        //so it only need two rows' vector
        vector<vector<int>> map(2, vector<int> (m, 0));
        
        for(int j=0;j<m;j++){
            if(A[A.size()-1]>j+1)
                map[1][j] = 0;
            else
                map[1][j] = A[A.size()-1];
        }
        
        for(int i=0;i<map.size();i++){
            if(A[i]>0+1)
                map[i][0] = 0;
            else
                map[i][0] = A[i];
        }
        
        for(int i=A.size()-2; i>=0; i--){
            for(int j=1; j<m; j++){
                if(j+1-A[i]<0){
                    map[0][j] = map[1][j];
                }else{
                    //if(i==2&&j==9)
                       // cout<<map[i+1][j-A[i]]<<endl;
                    if(A[i]+map[1][j-A[i]]>map[1][j]){
                        map[0][j]= A[i]+map[1][j-A[i]];
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