# 93. Restore IP Addresses

## Question link
(link)

## Question Description
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Example 1:

> Input: s = "25525511135"
> Output: ["255.255.11.135","255.255.111.35"]

Example 2:

> Input: s = "0000"
> Output: ["0.0.0.0"]

Example 3:

> Input: s = "1111"
> Output: ["1.1.1.1"]

Example 4:

> Input: s = "010010"
> Output: ["0.10.0.10","0.100.1.0"]

Example 5:

> Input: s = "101023"
> Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

Constraints:

0 <= s.length <= 3000
s consists of digits only.

## 解题思路
string
backtracking

## Code
```c++
//backtracking
class Solution {
private:
    vector<string> out;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return out;
        
        string tmp;
        int partCount = 0; //numbers of dot
        
        //backtracking
        backtrackingRecursive(s, 0, tmp, partCount);

        return out;     

    }

    void backtrackingRecursive(string& s, int startIndex, string tmp, int partCount){
        if(startIndex >= s.size()){
            
            //if part is 4 
            if(partCount == 4)
                out.push_back(tmp);
            
            return;
        }
        
        //part is 4 but index is not in s' end
        if(partCount == 4)
            return;
        
        for(int i = startIndex; i < startIndex + 3; i++){ //ip address is max 255,len is 3
            //avoid i over s'size
            if(i >= s.size()) break;
            
            //ip string
            string ip(s, startIndex, i - startIndex + 1);
            
            //check whether ip is vaild
            if(checkIpString(ip)){
                if(tmp.size() == 0){ //first part
                    string tmp_next = tmp + ip;
                    backtrackingRecursive(s, i + 1, tmp_next, partCount + 1);
                }else{
                    string tmp_next=tmp+"."+ip;
                    backtrackingRecursive(s, i + 1, tmp_next, partCount + 1);    
                }
            }
        }

        return;
    }

    //check ip is vaild or not
    bool checkIpString(string part){
        //first is 0' case, such as 010 is invaild.
        if(part[0] == '0'&& part.size() > 1) return false;

        int integer = atoi(part.c_str());
        
        //invaild ip case        
        if(integer > 255 || integer < 0)
            return false;
        
        return true;
    }
};
```

## Time Complexity Analysis