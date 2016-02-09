/*
331. Verify Preorder Serialization of a Binary Tree My Submissions Question
Total Accepted: 995 Total Submissions: 3018 Difficulty: Medium
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

*/

/*
DFS verify, I uses two stk, one stores numbers,
another stores left ot right branch.

for example,
strStk: 9, 3
directStk: L, 

it show 3 is Left node of 9.
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
	stack<string> strStk;
	stack<string> directStk;
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return false;
        int i=0;
        vector<string> numbers;
        string word;
        preorder=preorder+","; //for getting last numbers
        stringstream stream(preorder);
        while( getline(stream, word, ',') ){
            numbers.push_back(word);
        }
        
        while(i<numbers.size()){
            //cout<<numbers[i];
            string item=numbers[i];
            if(item!="#"){       
                /*
                 if number is not "#", store it in strStk,
                 and push L in directStk (it means go left)
                 */
                strStk.push(item);
                directStk.push("L");
            }else if(item=="#"){
                /*
                if number is "#", it need to check:
                1. directStk top is L (it means L leap is empty), pop directStk 
                and push R in it (we go right leap)
                2. directStk top is R (it means R leap is empty) , pop directStk and strStk looply until directStk's
                Top is L (keep popping all right leap nodes). then change directStk by pop L and push R.

                if in step 2 stacks are empty, it means DFS finished. in this condition, if all string are scanned.
                return true. otherwise return false.
                 */
                
                if(directStk.empty()) {  //cornner case: root is "#"
                    if(i==numbers.size()-1)
                        return true;
                    else
                        return false;  
                }
                if(directStk.top()=="L"){
                    directStk.pop();
                    directStk.push("R");
                }else if(directStk.top()=="R"){
                    while(directStk.top()!="L"){
                        directStk.pop();
                        strStk.pop();
                        if(directStk.empty() && strStk.empty()){
                            if(i==numbers.size()-1)
                                return true;
                            else
                                return false;  
                        }
                    }
                    directStk.pop();
                    directStk.push("R");
                }
            }

            i=i+1;
        }

        //if input string scan finished but stacks has not empty, return false;
        if(!strStk.empty()||!directStk.empty())
            return false;
        else
            return true;
    }
};


int main(){
    Solution s;
    string input1="9,3,4,#,#,1,#,#,2,#,6,#,#";
    string input2="1,#";
    string input3="9,#,#,1";
    
    cout<<s.isValidSerialization(input1)<<endl;
    cout<<s.isValidSerialization(input2)<<endl;
    cout<<s.isValidSerialization(input3)<<endl;
    
    return 0;
}


