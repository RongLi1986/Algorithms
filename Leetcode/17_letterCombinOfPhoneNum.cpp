/*
Letter Combinations of a Phone Number Total Accepted: 26479 Total Submissions: 99869 My Submissions Question Solution 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
1--null
2--abc
3--def
4--ghi
5--jkl
6--mno
7--pqrs
8--tuv
9--wxyz
0--null


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/*
rescursive:
it is like tree's BFS

递归的空间就是搜索树，在这题里面，
每一个数字基本上有三种可能字符，所以任意一个节点会有三种扩展，如果数字串长为L的话，时间复杂度就是O(3^L).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
private:
	vector<string> out;
public:
    vector<string> letterCombinations(string digits) {
        int size=digits.size();
        string s;
        letterCombinations(s, 0, size, digits);  //recurive

        return out;
    }

    void letterCombinations(string s, int i, int size, string &digits){
    	if(i<size){
    		if(digits[i]=='2'){
    			letterCombinations(s+'a', i+1, size, digits);
    			letterCombinations(s+'b', i+1, size, digits);
    			letterCombinations(s+'c', i+1, size, digits);
    		}else if(digits[i]=='3'){
    			letterCombinations(s+'d', i+1, size, digits);
    			letterCombinations(s+'e', i+1, size, digits);
    			letterCombinations(s+'f', i+1, size, digits);
    		}else if(digits[i]=='4'){
    			letterCombinations(s+'g', i+1, size, digits);
    			letterCombinations(s+'h', i+1, size, digits);
    			letterCombinations(s+'i', i+1, size, digits);
    		}else if(digits[i]=='5'){
    			letterCombinations(s+'j', i+1, size, digits);
    			letterCombinations(s+'k', i+1, size, digits);
    			letterCombinations(s+'l', i+1, size, digits);
    		}else if(digits[i]=='6'){
    			letterCombinations(s+'m', i+1, size, digits);
    			letterCombinations(s+'n', i+1, size, digits);
    			letterCombinations(s+'o', i+1, size, digits);
    		}else if(digits[i]=='7'){
    			letterCombinations(s+'p', i+1, size, digits);
    			letterCombinations(s+'q', i+1, size, digits);
    			letterCombinations(s+'r', i+1, size, digits);
    			letterCombinations(s+'s', i+1, size, digits);
    		}else if(digits[i]=='8'){
    			letterCombinations(s+'t', i+1, size, digits);
    			letterCombinations(s+'u', i+1, size, digits);
    			letterCombinations(s+'v', i+1, size, digits);
    		}else if(digits[i]=='9'){
    			letterCombinations(s+'w', i+1, size, digits);
    			letterCombinations(s+'x', i+1, size, digits);
    			letterCombinations(s+'y', i+1, size, digits);
    			letterCombinations(s+'z', i+1, size, digits);
    		}
    	}else{
    		out.push_back(s);
    	}
    }
};


int main(){
    Solution s;
    string ss="23";
    s.letterCombinations(ss);

    return 0;
}