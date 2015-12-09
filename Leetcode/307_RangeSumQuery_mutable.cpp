/*
Range Sum Query - Mutable My Submissions Question
Total Accepted: 2676 Total Submissions: 17580 Difficulty: Medium
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
Subscribe to see which companies asked this question
*/

/*
use binary Index Tree in this problem
https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/#introduction
*/



#include <iostream>
#include <vector>

using namespace std;
class NumArray {
int maxSize;
vector<int> bit;
vector<int> f;
public:
    NumArray(vector<int> &nums) {
        if(!nums.empty()){
            maxSize=nums.size();
            bit.resize(maxSize+1); //bit's begin index is 1
            f.resize(nums.size());
            f=nums;
            bit[0]=0;
            //build bit
            //bit[idx]=f[idx-2^r +1]+…+f[idx]
            for(int i=1;i<maxSize+1;i++){
                int r=findR(i);
                int j=i-pow(2,r)+1;
                //cout<<"r:"<<r<<" "<<"j:"<<j<<endl;
                while(j<=i){
                    bit[i]+=nums[j-1];
                    j++;
                }
            }
            
            /*
            for(int i=0;i<maxSize+1;i++){
                cout<<bit[i]<<" ";
            }
            cout<<endl;
            */
        }        
    }

    //find nums of zero start from right most 1
    //ex 1 is 0, 2 is 1, 4 is 2, 7 is 0
    int findR(int i){
        int count=0;
        while((i&1) !=1){
            i=i>>1;
            count++;
        }
        return count;
    }
    

    void update(int i, int val) {
        int delta=val-f[i];
        f[i]=val;

        i=i+1;  //bit's begin index is 1
        while(i<maxSize+1){
            bit[i]+=delta;
            i+=(i&-i);
            //cout<< "i is "<<i<<endl;
        }
        //cout<<"update"<<endl;
    }

    int read(int i){
        i=i+1; //bit's begin index is 1
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i& -i);
        }
        
        return sum;
    }

    int sumRange(int i, int j) {
        int sum1=read(i-1);
        int sum2=read(j);
        //cout<<sum2-sum1<<endl;
        return sum2-sum1;
    }
    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
int main(){
    
    return 0;
}