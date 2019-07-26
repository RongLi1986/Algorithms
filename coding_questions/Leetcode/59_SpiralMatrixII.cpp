/*
Spiral Matrix II Total Accepted: 24679 Total Submissions: 78278 My Submissions Question Solution 
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]

*/

/*
this question is same with spiral Matrix I,
but first we need to create a Matrix;
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> rowVector(n,0);

        //create a matrix
        vector<vector<int> > out;
        for(int i=0;i<n;i++)
        	out.push_back(rowVector);

        int rowSzie=n;
        int colSize=n;
        int numMatrix=n*n;

        //current index;
        int initialRow=0;
        int initialCol=0;

        int right=colSize;
        int down=rowSzie-1;
        int left=colSize-1;
        int up=rowSzie-2;
        
        int i=0;
        while(1){
            //check stop
        	if(i==numMatrix) break;
        	
            //go right
        	int a=0;
            //cout<<right<<endl;
        	while(a<right){
        		out[initialRow][initialCol]=i+1;
                //cout<<i<<endl;
                if(a==right-1)
                  initialRow++;  
                else
        		  initialCol++;
        		i++;
        		a++;
        	}
        	right=right-2; 

        	if(i==numMatrix) break;
        	//go down
        	int b=0;
        	while(b<down){
        		out[initialRow][initialCol]=i+1;
                //cout<<i<<endl;
                if(b==down-1)
                  initialCol--;  
                else
                  initialRow++;
        		i++;
        		b++;
        	}
        	down=down-2; 
        	
        	if(i==numMatrix) break;
        	//do left
        	int c=0;
        	while(c<left){
        		out[initialRow][initialCol]=i+1;
        		//cout<<i<<endl;
                if(c==left-1)
                  initialRow--;  
                else
                  initialCol--;
        		i++;
        		c++;
        	}
        	left=left-2; 
        	
        	if(i==numMatrix) break;
        	int d=0;
        	while(d<up){
        		out[initialRow][initialCol]=i+1;
                if(d==up-1)
                  initialCol++;  
                else
                  initialRow--;
        		i++;
        		d++;
        	}
        	up=up-2;         	
        }

        return out;
    }
};




int main(){
	Solution s;
	vector<vector<int> > out=s.generateMatrix(2);

	for(int i=0;i<out.size();i++)
		for(int j=0;j<out[0].size();j++){
			cout<<out[i][j]<<" ";
		}

	cout<<endl;

	return 0;
}