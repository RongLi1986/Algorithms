/*Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


/*
sol1:
for each row, first item and last item should be 1, and others
follow rule:
    res[i][j]=res[i-1][j-1]+res[i-1][j];

both recursive and iterative could solve it.

sol2:

the true way is
The nth row of pascal triangle will have the following format: 
1 a(1) a(2) ... a(n) here we have a(n) = 1; a(k+1) = a(k) * (n-k)/(k+1).
*/



#include <iostream>
#include <vector>
using namespace std;


//iterative
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        
        int i=0;
        while(i<numRows){
            vector<int> tmp(i+1,1);
            for(int j=1;j<i;j++){
                tmp[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(tmp);
            i++;
        }
        
        return res;
    }
};

//recursive
class Solution_old {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > v;
        if(numRows==0) return v;  //corner case
        if(numRows==1){
        	vector<vector<int> > v;
        	vector<int> v1={1};
        	v.push_back(v1);
        	return v;
        }
        else if(numRows==2){
        	vector<vector<int>> v=generate(numRows-1);
        	vector<int> v1={1,1};
        	v.push_back(v1);
        	return v;
        }
        else{
        	vector<vector<int> > v=generate(numRows-1);
        	vector<int> v_out;
        	for(int i=0;i<numRows;i++){
        		if(i==0||i==numRows-1){
        			v_out.push_back(1);
        		}else{
        			v_out.push_back(v[numRows-2][i-1]+v[numRows-2][i]);
        		}
        	}
        	v.push_back(v_out);
        	return v;
        } 
        	 
    }
};

int main(){
	Solution s;
	vector<vector<int> > v=s.generate(6);
	
	for ( std::vector<std::vector<int>>::size_type i = 0; i < v.size(); i++ ){
   		for ( std::vector<int>::size_type j = 0; j < v[i].size(); j++ ){
      		std::cout << v[i][j] << ' ';
   		}
   		std::cout << std::endl;
	}

	return 0;
}