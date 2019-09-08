/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Have you met this question in a real interview? Yes
Example
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]
*/


/*

*/

class Solution {
private:
    unordered_map<int, int> xMap;
    unordered_map<int, int> yMap;
    unordered_map<int, int> xyMap;  //  "/" x+y
    unordered_map<int, int> yxMap;  //  "\" x-y
    vector<vector<string> > res;
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        initialMap(n);
        vector<string> tmp;
        totalNQueensHelper(0, n, tmp);
        return res;
    }
    
    void totalNQueensHelper(int startX, int n, vector<string> &tmp){
        if(tmp.size()==n){
            res.push_back(tmp);
            return;
        }
        
        for(int y = 0; y < n; y++){
            if(xMap[startX]==0 && yMap[y]==0
                && xyMap[startX+y]==0 && yxMap[startX-y]==0){
                //cout<<"x"<<startX<<"y"<<y<<endl;
                string str(n, '.');
                str[y]='Q';
                
                tmp.push_back(str);
                
                xMap[startX] = 1; 
                yMap[y] = 1;
                xyMap[startX+y] = 1; 
                yxMap[startX-y] = 1;
                
                totalNQueensHelper(startX+1,n, tmp);
                
                xMap[startX] = 0; 
                yMap[y] = 0;
                xyMap[startX + y] = 0; 
                yxMap[startX - y] = 0;
                
                tmp.pop_back();
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