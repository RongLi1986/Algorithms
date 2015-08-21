/*
Permutation Sequence Total Accepted: 21726 Total Submissions: 96507 My Submissions Question Solution 
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/


/*
思路1：
可以用递归遍历所有可能的排列 然后找出第k个。这样时间复杂度会很高.


思路2：
n个数的的第k个排列为：
a1, a2, a3,...an;
选取的第一个数应该为第
K1 = k；
a1 = K1/(n-1)!位数字
同理当选完a1后只剩下n-1个数字，在确定第二个数应该选择哪个.
a2 = K2 / (n-2)!
K2 = K1 % (n-1)!

equation is 
a(i)=k(i)/(n-i)!
k(i)=k(i-1)%(n-i-1)!

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
		for(int i=0;i<n;i++){
			num.push_back(i+1);
		}

		string out="";
		k--;
		int ktmp=k;
		int fact=Factorial(n);
		for(int i=0;i<n;i++){
			
			fact= fact/(n-i);
			int index=ktmp/fact;


			//string also could push back
			out.push_back(num[index]+'0');


			num.erase(num.begin()+index);
			ktmp=ktmp%fact;

		}

		return out;
    }

    int Factorial(int x) {
  		return (x == 1 ? x : x * Factorial(x - 1));
	}
};

int main(){
	Solution s;
	cout<<s.getPermutation(3,1)<<endl;
	cout<<s.getPermutation(3,2)<<endl;
	cout<<s.getPermutation(3,3)<<endl;
	cout<<s.getPermutation(3,4)<<endl;
	cout<<s.getPermutation(3,5)<<endl;
	cout<<s.getPermutation(3,6)<<endl;

	return 0;
}