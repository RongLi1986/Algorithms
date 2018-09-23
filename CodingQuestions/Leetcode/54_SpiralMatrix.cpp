/*
Spiral Matrix 
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*
use a loop, then following the spiral rule:
right, down, left, up.
each time, it need to update a length 
check i count, if equal to total item in Matrix.
break the loop
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> out;
        if(matrix.size()==0)
        	return out;

        int rowSize=matrix.size();
        int colSize=matrix[0].size(); 
        
        //items counts
        int i=0;

        //each row and col numbers
        int right=colSize;
        int down=rowSize-1;
        int left=colSize-1;
        int up=rowSize-2;

        //currnt index 
        int initalRow=0;
        int initalCol=0;
        while(1){
            //check if it should stop
        	if(i==rowSize*colSize) break;
        	//right
        	int a=0;  //for counting in right
        	while(a<right){
        		out.push_back(matrix[initalRow][initalCol]);
        		i++;

        		if(a<right-1){ //continue go to right
        			initalCol++;
        			a++;
        		}else{  //move to down
        			a++;
        			initalRow++;
        		}

        	}
            //update new right length
        	right-=2;  


            //check if it should stop
        	if(i==rowSize*colSize) break;
        	//down
        	int b=0; //counting down
        	while(b<down){
        		out.push_back(matrix[initalRow][initalCol]);
        		i++;
        		if(b<down-1){
        			initalRow++;
        			b++;
        		}else{
        			b++;
        			initalCol--;
        		}
        	}
            //update new down
        	down-=2;


        	if(i==rowSize*colSize) break;
        	//left
        	int c=0;
        	while(c<left){
        		out.push_back(matrix[initalRow][initalCol]);
        		i++;
        		if(c<left-1){
        			initalCol--;
        			c++;
        		}else{
        			c++;
        			initalRow--;
        		}
        	}
        	left-=2;

        	if(i==rowSize*colSize) break;
            //up
        	int d=0;
        	while(d<up){
        		out.push_back(matrix[initalRow][initalCol]);
        		i++;
        		if(d<up-1){
        			initalRow--;
        			d++;
        		}else{
        			d++;
        			initalCol++;
        		}
        	}
        	up-=2;
        }

        return out;
    }
};

int main(){
	vector<int> a={1,2,3,4};
	vector<int> b={4,5,6,4};
	vector<int> c={7,8,9,4};
	vector<int> d={7,8,9,4};

	vector<vector<int> > in;
	in.push_back(a);
	in.push_back(b);
	in.push_back(c);
	in.push_back(d);

	vector<vector<int> > in2;
	vector<int> tmp={1,2};
	in2.push_back(tmp);

	Solution s;
	vector<int> out=s.spiralOrder(in);

	for(int i=0;i<out.size();i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;

	return 0;
}