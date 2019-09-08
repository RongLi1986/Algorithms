/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Have you met this question in a real interview? Yes
Example
For n=4, there are 2 distinct solutions.
*/


/*

*/

class Solution {
private:
    unordered_map<int, int> xMap;
    unordered_map<int, int> yMap;
    unordered_map<int, int> xyMap;  //  "/" x+y
    unordered_map<int, int> yxMap;  //  "\" x-y
    int res;
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        res=0;
        initialMap(n);
        
        totalNQueensHelper(0, 0, n);
        return res;
        
    }
    
    void totalNQueensHelper(int count, int startX, int n){
        if(count==n){
            res++;
            return;
        }
        
        for(int y = 0; y < n; y++){
            if(xMap[startX]==0 && yMap[y]==0
                && xyMap[startX+y]==0 && yxMap[startX-y]==0){
                //cout<<"x"<<startX<<"y"<<y<<endl;
                xMap[startX] = 1; 
                yMap[y] = 1;
                xyMap[startX+y] = 1; 
                yxMap[startX-y] = 1;
                
                totalNQueensHelper(count+1,startX+1,n);
                
                xMap[startX] = 0; 
                yMap[y] = 0;
                xyMap[startX + y] = 0; 
                yxMap[startX - y] = 0;
            }
        }
        
        return;
    }
    
    void initialMap(int n ){
        for(int i=0; i<n; i++){
            xMap[i] = 0;
            yMap[i] = 0;
        }
        
        for(int i=-n+1; i<n; i++){
            yxMap[i] = 0;
        }
        
        for(int i=0;i<2*n-1;i++){
            xyMap[i] = 0;
        }
    }
};
