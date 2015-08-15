/*
Set Matrix Zeroes 
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.
*/

/*
basic way is O(m+n)space , use vector m and n to keep which row and col 
should be zero

it also can be done by O(1) space.
*/


#include <iostream>
#include <vector>
using namespace std;

//O(1) space, so fancy
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if(matrix.empty()) return;

        int m = matrix.size();
        int n = matrix[0].size();

        int row = -1, col = -1;
        for(int i=0; i<m; i++){
            if(row != -1) break;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        cout<<row<<endl;
        cout<<col<<endl;
        
        if(row == -1) return;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][col] = 0;
                    matrix[row][j] = 0;
                }
            }
        }
        for(int i=0; i<m; i++){
            if(i == row) continue;
            if(matrix[i][col] == 0){
                for(int j=0; j<n; j++) matrix[i][j] = 0;
            }
        }
        for(int j=0; j<n; j++){
            if(j == col) continue;
            if(matrix[row][j] == 0){
                for(int i=0; i<m; i++) matrix[i][j] = 0;
            }
        }
        for(int i=0; i<m; i++) matrix[i][col] = 0;
        for(int j=0; j<n; j++) matrix[row][j] = 0;
    }
};


//O(m+n) space
class Solution_old {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> vRow(m,0);
        vector<int> vCol(n,0);
        int i=0;
        int j=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    vRow[i]=1;
                    vCol[j]=1;
                }       
            }
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(vRow[i]==1||vCol[j]==1){
                    matrix[i][j]=0;
                }       
            }
        }

    }
};

int main(){
    vector<int> a={1,1,1,0};
    vector<int> b={1,0,1,1};
    vector<int> c={1,1,1,1};
    vector<int> d={1,1,0,1};
    vector<vector<int> > mat;
    mat.push_back(a);
    mat.push_back(b);
    mat.push_back(c);
    mat.push_back(d);

    Solution s;
    s.setZeroes(mat);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
