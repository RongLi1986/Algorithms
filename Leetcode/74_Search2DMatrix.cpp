/*
Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

/*
use binary search 2 for row and col;
*/

#include <iostream>
#include <vector>
using namespace std;

//O(lg(n)*lg(n))
class Solution {
public:
    //lg(n)*lg(n)
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int size=matrix.size();
        
         //linear s
        int start=0;
        int end=size-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(mid<size-1){
                if(target>=matrix[mid][0]&&target<matrix[mid+1][0]){
                    return binarySearch(matrix[mid],target);
                }else if(target<matrix[mid][0]){
                    end=mid-1;
                }else{ //larger than matrix[mid+1][0]
                    start=mid+1;
                }
                
            }else{
                return binarySearch(matrix[size-1],target);;        
            }
            
        }

    }

    bool binarySearch(vector<int> &array, int target){
        int size=array.size();
        int left=0;
        int mid=0;
        int right=size-1;
        while(left<=right){
            mid=(left+right)/2;
            if(target==array[mid])
                return true;
            else if(target<array[mid])
                right=mid-1;
            else if(target>array[mid])
                left=mid+1;
        }

        return false;
    }
};


//O(n*lg(n))
class Solution_old {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	int size=matrix.size();
    	        
        //linear s
        int i=0;
    	while(i<size-1){
    		if(target>=matrix[i][0]&&target<matrix[i+1][0]){
    			return binarySearch(matrix[i],target);
    		}
    		i++;
    	}

        return binarySearch(matrix[size-1],target);;
        
    }

    bool binarySearch(vector<int> &array, int target){
    	int size=array.size();
    	int left=0;
    	int mid=0;
    	int right=size-1;
    	while(left<=right){
    		mid=(left+right)/2;
    		if(target==array[mid])
    			return true;
    		else if(target<array[mid])
    			right=mid-1;
    		else if(target>array[mid])
    			left=mid+1;
    	}

    	return false;
    }
};

int main(){
	vector<vector<int> > matrix;
	vector<int> a={1,   3,  5,  7};
	vector<int> b={10, 11, 16, 20};
	vector<int> c={23, 30, 34, 50};
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);

	Solution s;

	cout<<s.searchMatrix(matrix,-1)<<endl; //0
    cout<<s.searchMatrix(matrix,0)<<endl;  //0
    cout<<s.searchMatrix(matrix,3)<<endl;   //1
    cout<<s.searchMatrix(matrix,4)<<endl;   //0
    cout<<s.searchMatrix(matrix,11)<<endl;  //1
    cout<<s.searchMatrix(matrix,17)<<endl;  //0
    cout<<s.searchMatrix(matrix,34)<<endl;  //1
    cout<<s.searchMatrix(matrix,80)<<endl;  //0
	return 0;
}