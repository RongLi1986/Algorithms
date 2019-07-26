/*
Gray Code Total Accepted: 25771 Total Submissions: 79541 My Submissions Question Solution 
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/


/*
recursive way and math rule is:
if n==0 res is [0]
for others, res(n)=res(n-1)+reverse(res(n-1)+2^(n-1)

tips:
n=k时的Gray Code，等于n=k-1时的Gray Code的逆序 加上 1<<k
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        
        if(n==0){ //base case;
            vector<int> res;
            res.push_back(0);
            return res;
        }
         
        vector<int> last=grayCode(n-1);
        vector<int> relast=last;
        reverse(relast.begin(),relast.end());
        
        for(int i=0;i<relast.size();i++){
            last.push_back(relast[i]+pow(2,(n-1)));
        }
        
        return last;
    }
};

int main(){
	Solution s;
	vector<int> out=s.grayCode(4);

	int size=out.size();

    for(int i=0;i<size;i++)
      	cout<<out[i]<<" ";
     cout<<endl;

	return 0;
}