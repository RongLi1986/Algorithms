# 6. ZigZag Conversion

## Question link
(https://leetcode.com/problems/zigzag-conversion/solution/)

## Question Description
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I


## 解题思路
in comment.
time complexity: O(n)
space complexity: O(n-2) => O(n)

```c++
class Solution {
public:
    string convert(string s, int nRows) {
        //corner cases
        //"AB" 1
        //"PAY" 3
      	if(s.size() <= nRows || nRows == 1) return s;
        
        string sc[nRows];
        unordered_map<int, int> lut;
        
        //create mapping between string index and row index
        /*
        0       8
        1     7    ==>  <7, 1> ==> 7 - 6  
        2   6      ==>  <6, 2> ==> 6 - 4  }   int t = 2; row = index - t ; t = t + 2
        3 5        ==>  <5 ,3> ==> 5 - 3
        4          
        */
        int t = 2;
        for(int i = nRows; i < 2 * nRows - 2 ; i++){
            lut[i] = i - t;
            t = t + 2;
        }
        
        //iterate string and push char in sc array
        for(int i = 0;i < s.size(); i++){
            int m = i % (2 * (nRows - 1));
            if (m < nRows){
                sc[m] += s[i];
            }else if(m >= nRows && m < 2 * nRows - 2){
                int k = lut[m];
                sc[k] += s[i];
            }
        }
        
        //convert sc array to ans
        string ans;
        for(int i = 0; i < nRows; i++){
        	//cout<<sc[i]<<endl;
        	ans += sc[i];
        }
        
    	return ans; 
    }
};
```