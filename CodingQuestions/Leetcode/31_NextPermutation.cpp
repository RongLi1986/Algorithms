/*
Next Permutation 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

/*
ex      6 8 7 4 3 2
step1:  6_ 8 7 4 3 2
step2:  6_ 8 7_ 4 3 2
step3:  7 (8 6 4 3 2)
step4:  7 2 3 4 6 8


Algorithm:
1. from right to left, find the first digit which(P) violate the increase trend.
2. From right to left, find the first digit(S) which larger than P
3. swap P and S.
4. reverse(sort) all the digit on the right of P's Index
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size=num.size();
        int changeIndex=-1;
        
        for(int i=size-1;i>0;i--){
            if(num[i]>num[i-1]){
                changeIndex=i-1;
                for(int j=size-1;j>changeIndex;j--){
                	if(num[j]>num[changeIndex]){
                		swap(num, j, changeIndex);
                		sort(num.begin()+changeIndex+1, num.end());
                		return;
                	}
                }
            }
        }
        
        if(changeIndex==-1)
            sort(num.begin(),num.end());
       
    }
    
    void swap(vector<int> &num,int origIndex, int changeIndex){
        int tmp=num[changeIndex];
        num[changeIndex]=num[origIndex];
        num[origIndex]=tmp;
    }
};

int main(){
	Solution s;
	vector<int> v={1,3,2}; 
	int size=v.size();
	s.nextPermutation(v);


	for(int i=0;i<size;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;


	return 0;
}