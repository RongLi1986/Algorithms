/*Pascal's Triangle II Total Accepted: 23716 Total Submissions: 79275
	Given an index k, return the kth row of the Pascal's triangle.

	For example, given k = 3,
	Return [1,3,3,1].

	Note:
	Could you optimize your algorithm to use only O(k) extra space?
*/

/*
we could use same sol as last question, but only return targert row.
but it use more space.


the true way is
The nth row of pascal triangle will have the following format: 
1 a(1) a(2) ... a(n) here we have a(n) = 1; a(k+1) = a(k) * (n-k)/(k+1).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> last_tmp;
        int i=0;
        while(i<=k){
            vector<int> tmp(i+1,1);
            for(int j=1;j<i;j++){
                tmp[j]=last_tmp[j-1]+last_tmp[j];
            }
            i++;
            last_tmp=tmp;
            tmp.clear();
        }
        
        return last_tmp;
    }
};

class Solution_old {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > v;
        if(numRows<=0) return v;  //corner case
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

    vector<int> getRow_old(int rowIndex) {
    	vector<vector<int> > v=generate(rowIndex+1);

    	return v[rowIndex];
    }

    //follow the mathmatic equalation
    /*
    The nth row of pascal triangle will have the following format: 
    1 a(1) a(2) ... a(n) here we have a(n) = 1; a(k+1) = a(k) * (n-k)/(k+1).
    */
    vector<int> getRow(int rowIndex) {
    	vector<int> results;

        if(rowIndex<0) return results;

        results.push_back(1);  //first 1
        if(rowIndex == 0) return results;
        long long pre = 1; 
        for(int k = 0; k<rowIndex; k++){
            pre = pre * (rowIndex-k)/(k+1);  //need double
            results.push_back(static_cast<int>(pre));
        }

        return results;
    }
};

int main(){
	Solution s;
	vector<vector<int> > v=s.generate(6);
	
	for ( std::vector<std::vector<int> >::size_type i = 0; i < v.size(); i++ ){
   		for ( std::vector<int>::size_type j = 0; j < v[i].size(); j++ ){
      		std::cout << v[i][j] << ' ';
   		}
   		std::cout << std::endl;
	}

	std::cout<<std::endl;
	
	vector<int> v1=s.getRow(1);
	
	for ( std::vector<int>::size_type j = 0; j < v1.size(); j++ ){
      		std::cout << v1[j] << ' ';
   	}
   	std::cout << std::endl;


	return 0;
}