/*
N-Queens II Total Accepted: 26167 Total Submissions: 73463 My Submissions Question Solution 
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/*
basic idea: backtracking
*/

#include <iostream>
#include <unordered_set>

using namespace std;

//replace by array 
class Solution{
private:
    int count;
    
    int* rowSet;
    int* colSet;
    int* diagSetPos;
    int* diagSetNeg;
public:
    int totalNQueens(int n) {
        if(n<=0) return 0;
        count=0;
        
        //inital broad array
        rowSet=new int[n];
        colSet=new int[n];
        diagSetPos=new int[2*n-1];
        diagSetNeg=new int[2*n-1];
        
        for(int i=0;i<n;i++){
            rowSet[i]=0;
            colSet[i]=0;
        }
        
        
        for(int i=0;i<2*n-1;i++){
            diagSetPos[i]=0;
            diagSetNeg[i]=0;
        }

        checkQueen(0,n);

        //release mem
        delete rowSet;
        delete colSet;
        delete diagSetPos;
        delete diagSetNeg;

        return count;
    }

    void checkQueen(int row, int size){
        if(row==size) {
            count++;
            return;
        }
        for(int i=0;i<size;i++){
            if(validPos(row,i,size)){
                rowSet[row]=1;
                colSet[i]=1;
                diagSetPos[row+i]=1;
                diagSetNeg[row-i+size-1]=1;   
                
                checkQueen(row+1,size);
                
                rowSet[row]=0;
                colSet[i]=0;
                diagSetPos[row+i]=0;
                diagSetNeg[row-i+size-1]=0;
            }
        }
    }

    bool validPos(int row, int col, int size){
        if(rowSet[row]==1){
            return false;
        }
        if(colSet[col]==1){
            return false;
        }
        if(diagSetPos[row+col]==1){
            return false;
        }
        if(diagSetNeg[row-col+size-1]==1){
            return false;
        }
        return true;
    }
};


//TODO:these sets are waste time
class Solution_old {
private:
	unordered_set<int> rowSet;
	unordered_set<int> colSet;
	unordered_set<int> diagSetPos;
	unordered_set<int> diagSetNeg;
	int count;
public:
    int totalNQueens(int n) {
        if(n<=0) return 0;
    	count=0;
        
        checkQueen(0,n);
    	return count;
    }

    void checkQueen(int row, int size){
    	if(row>=size) {
    		count++;
    		return;
    	}
    	for(int i=0;i<size;i++){
    		if(validPos(row,i,size)){
    			rowSet.insert(row);
    			colSet.insert(i);
    			diagSetPos.insert(row+i);
    			diagSetNeg.insert(row-i);	
    			checkQueen(row+1,size);
    			rowSet.erase(row);
    			colSet.erase(i);
    			diagSetPos.erase(row+i);
    			diagSetNeg.erase(row-i);
    		}
    	}
    }

    bool validPos(int row, int col, int size){
    	if(rowSet.find(row)!=rowSet.end()){
    		return false;
    	}
    	if(colSet.find(col)!=colSet.end()){
    		return false;
    	}
    	
    	if(diagSetPos.find(row+col)!=diagSetPos.end()){
    		return false;
    	}
    	if(diagSetNeg.find(row-col)!=diagSetNeg.end()){
    		return false;
    	}
    	
    	return true;
    }
};

int main(){
	Solution s;
	for(int i=0;i<10;i++)
		cout<<s.totalNQueens(i)<<endl;
	return 0;
}