/*
Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|

 Notice

You can assume each number in the array is a positive integer and not greater than 100.

Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.

Return 2.
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        
        if(A.empty()) return 0;
        vector<int> B (A.size(), 0);
        
        for(int i=0;i<B.size();i++)
            B[i] = A[i];
        
        
        vector<vector<int> > map(A.size(), vector<int>(100,INT_MAX));
        
        return recursive(A, B, target, 0, map);
        
        
    }
    
    int recursive(vector<int> A, vector<int> B, int target, int index, vector<vector<int> >& map){
        //cout<<index<<endl;
        if(index>= A.size())
            return 0;
            
        int diff;
        int minVal=INT_MAX;
        
        for(int i=1;i<100;i++){
            
            if(index!=0 ){
                if(abs(i-B[index-1])>target)
                    continue;
            }
            
            B[index]=i;
            
            if (map[index][i - 1] != INT_MAX) {
                diff = map[index][i - 1];
                minVal = min(diff,minVal);
                continue;
            }
            
            diff = abs(i-A[index]);
            diff += recursive(A,B,target,index+1, map);
            
            minVal = min(diff,minVal);
            map[index][i - 1] = diff;
            
            B[index] = A[index];
            
        }
        
        return minVal;
    }
    
};

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        
        if(A.empty()) return 0;
        vector<int> B (A.size(), 0);
        
        for(int i=0;i<B.size();i++)
            B[i] = A[i];
        
        return recursive(A, B, target, 0);
        
        
    }
    
    int recursive(vector<int> A, vector<int> B, int target, int index){
        //cout<<index<<endl;
        if(index>= A.size())
            return 0;
            
        int diff;
        int minVal=INT_MAX;
        
        for(int i=0;i<100;i++){
            
            if(index!=0 ){
                if(abs(i-B[index-1])>target)
                    continue;
            }
            
            B[index]=i;
            
            diff = abs(i-A[index]);
            diff += recursive(A,B,target,index+1);
            
            minVal = min(diff,minVal);
            
            B[index] = A[index];
            
        }
        
        return minVal;
    }
    
};