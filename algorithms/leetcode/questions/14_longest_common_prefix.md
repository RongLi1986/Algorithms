# 11 Container With Most Water

## Question link
(https://leetcode.com/problems/longest-common-prefix/description/)

## Question Description
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


## 解题思路
For the LCP of set of strings (s1 ... sn) = LCP(LCP(LCP(s1,s2), s3)..., sn) 
Time complexity: O(n)
Space complexity: O(1)

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string prefix;

    	if(strs.empty())  //vector is empty
    		return prefix;

    	prefix += strs[0]; //set first string

    	for(int i = 1;i < strs.size();i++){
            if(prefix.empty()) return prefix;
    		int j = 0;
    		while(j < prefix.size() && j < strs[i].size()){
    			if(prefix[j] != strs[i][j])
    				break;
    			j++;
    		}
    		prefix.clear();
    		prefix = strs[i].substr(0,j);  //update new string
    	}

    	return prefix;
    }
};
```