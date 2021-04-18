# 76. Minimum Window Substring

## Question link
(https://leetcode.com/problems/minimum-window-substring/description/)

## Question Description

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


## 解题思路
slide window 

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        //init a collection or int value to save the result according the question.
        string res = "";
        if(t.size() > s.size()) return res;
        
        //create a hashmap to save the Characters of the target substring.
        int hash[256]={0};
        
        for(char c : t){
            hash[c]++;
        }
        
        //maintain a counter to check whether match the target string.
        int counter = t.size();//must be the string size, NOT the map size because the char may be duplicate.
        
        //Two Pointers: begin - left pointer of the window; end - right pointer of the window
        int begin = 0, end = 0;

        //loop at the begining of the source string
        while(end < s.size()){
            
            char c = s[end];//get a character
            
            if( hash[c]>0 ){
                counter--;//modify the counter according the requirement(different condition).
            }
            hash[c]--;
            end++;
            
            //increase begin pointer to make it invalid/valid again
            while(counter == 0){ /* counter condition. different question may have different condition */
                string tmp = s.substr(begin, end-begin);
                
                if(res.size() == 0 || res.size() > tmp.size()){
                    res = tmp;
                }
                
                char tempc = s[begin];//***be careful here: choose the char at begin pointer, NOT the end pointer
                
                if(hash[tempc]>=0){
                    counter++;
                }
                
                /* save / update(min/max) the result if find a target*/
                // result collections or result int value
                hash[tempc]++;
                begin++;
            }
        }
        
        return res;
    }
};
```


