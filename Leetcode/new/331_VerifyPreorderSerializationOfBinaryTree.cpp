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
        //int flag=0;  //0 is L, 1 is R
        vector<string> numbers;
        string word;
        preorder=preorder+","; //for getting last numbers
        //cout<<preorder1<<endl;
        stringstream stream(preorder);
        while( getline(stream, word, ',') ){
            //cout << word << "\n";
            numbers.push_back(word);
        }
        
        while(i<numbers.size()){
            //cout<<numbers[i];
            string item=numbers[i];
            if(item!="#"){
                strStk.push(item);
                directStk.push("L");
                /*
                if(flag==0){
                    directStk.push("L");
                    flag=0;
                }else if(flag==1){
                    directStk.push("R");
                    flag=0;
                }*/
            }else if(item=="#"){
                if(directStk.empty()) {  //first "#"
                    if(i==numbers.size()-1)
                        return true;
                    else
                        return false;  
                }
                if(directStk.top()=="L"){
                    directStk.pop();
                    directStk.push("R");
                    //flag=0;  
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
                    //flag=0;
                }
            }

            i=i+1;  //skip ','
        }

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


