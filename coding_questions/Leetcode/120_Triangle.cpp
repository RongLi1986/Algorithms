/*
Triangle  
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/

/*
DP:
update each row value to minimun path sum in triangle.
equation is:
    triangle[i][0]+=triangle[i-1][0];  //j==0 (first one)
    triangle[i][num-1]+=triangle[i-1][num-2];  //j=num-1 (last one)
	triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]) (others)
and find smallest number from angle's last row
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int row=triangle.size();

        //use DP on triangle, 
        for(int i=1;i<row;i++){
            int num=triangle[i].size();
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][num-1]+=triangle[i-1][num-2];
            for(int j=1;j<num-1;j++){
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }

        //find smallest value from last row in triangle
        int minPath=INT_MAX;
        for(int i=0;i<triangle[row-1].size();i++){
            if(minPath>triangle[row-1][i])
                minPath=triangle[row-1][i];
        }
        
        return minPath;
    }
};



class Solution_old{
public:
	//TLE
	int minimumTotal_TLE(vector<vector<int> > &triangle){
		return findminSum(triangle,0, 0, 0);
	}

	int findminSum(vector<vector<int> > &triangle, int startCol, int startRow, int sum){
		sum=sum+triangle[startCol][startRow];
		if(triangle.size()==startCol+1){
			return sum;
		}else{
			return min(findminSum(triangle,startCol+1,startRow,sum),findminSum(triangle,startCol+1,startRow,sum));
		}
	}

	int minimumTotal(vector<vector<int> > &triangle){
		vector<vector<int> > sum;
		int colSize=triangle.size();

		for(int i=0;i<colSize;i++){
			int rowSize=triangle[i].size();
			//cout<<rowSize<<endl;
			vector<int> tmp;
			for(int j=0;j<rowSize;j++){
				if(i==0) {
					tmp.push_back(triangle[i][j]);
					
				}else{
					if(j==0){
						tmp.push_back(triangle[i][j]+sum[i-1][j]);
					}else if(j==rowSize-1){
						tmp.push_back(triangle[i][j]+sum[i-1][j-1]);
					}else{
						tmp.push_back(triangle[i][j]+min(sum[i-1][j-1],sum[i-1][j]));
					}
				}
			}
			sum.push_back(tmp);
		}
		
		return *min_element(sum[colSize-1].begin(),sum[colSize-1].end());

		//return (*minTotal);
	}

};

int main(){
	vector<vector<int> > triangle;
	vector<int> row={0};
	vector<int> row1={1,2};
	vector<int> row2={3,4,5};

	triangle.push_back(row);
	triangle.push_back(row1);
	triangle.push_back(row2);

	Solution s;
	cout<<s.minimumTotal(triangle)<<endl;

	return 0;
}