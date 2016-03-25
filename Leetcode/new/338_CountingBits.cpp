/*
338. Counting Bits My Submissions Question
Total Accepted: 5328 Total Submissions: 9728 Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

/*
think this as a binary tree
0~0
1~1
2~1 3~2
4~1 5~2 6~2 7~3

====>>      1
        1       2
      1   2   2   3

for i, it could find its parent value by using i>>1
and if i is left child, i&1==0
else i is right child

So, it could use DP function:

f[i]=(i&1)+f[i >> 1];
*/

class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i=1;i<=num;i++){
            res[i]=(i&1)+res[i >> 1];
        }
        
        return res;
    }
    
};


//basic way  O(n*sizeof(int))
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++){
            res.push_back(findOne(i));
        }
        
        return res;
    }
    
    int findOne(int num){
        int count=0;
        
        while(num!=0){
            count++;
            num=num&(num-1);
        }
        
        return count;
    }
};

int main(){

    return 0;
}