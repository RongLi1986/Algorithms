/*
Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//time O(n^2) and memory O(n^2) 
    void rotate(vector<vector<int> > &matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int> > tmp=matrix;
        //tmp.resize(9);

        for(int r = 0; r < row; r++)
        {
           for(int c = 0; c < col; c++)
           {
              // Hint: Map each source element indices into
              // indices of destination matrix element.
               tmp[ c ] [ row - r - 1 ] = matrix [ r ] [ c ];
           }
        }
        
        matrix.clear();
        matrix=tmp;
        
    }

    //in place, swap items  O(n!)
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int r=matrix.size();
        int c=matrix[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=i;j<c;j++){  //j=i, we only need to travese half matrix 
                if(i!=j){
                    //swap item
                    int tmp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=tmp;
                }
            }
        }
        
        //O(n^2)
        for(int i=0;i<r;i++)
            reverse(matrix[i].begin(),matrix[i].end());
            
        return;
    }

    
};


int main(){
	vector<vector<int> > matrix;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);

	matrix.push_back(tmp);
	matrix.push_back(tmp);
	matrix.push_back(tmp);

	int row=matrix.size();
	int col=row;

	for(int r = 0; r < row; r++)
    {
       for(int c = 0; c < col; c++)
       {
          // Hint: Map each source element indices into
          // indices of destination matrix element.
           cout<< matrix [ r ] [ c ] <<" ";
       }
       cout<<endl;
    }



	Solution s;
	s.rotate(matrix);



	
	for(int r = 0; r < row; r++)
    {
       for(int c = 0; c < col; c++)
       {
          // Hint: Map each source element indices into
          // indices of destination matrix element.
           cout<< matrix [ r ] [ c ] <<" ";
       }
       cout<<endl;
    }

	return 0;
}