/*
Palindrome Linked List Total Accepted: 266 Total Submissions: 932 My Submissions Question Solution 
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <cassert>

using namespace std;


/*
(TLE now!!)
scan this linkedlist and generate two strings,
one is from head to tail;
other is from tail to head;
compare two strings

update to vector, and AC
*/


/**
 *Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* ptr=head;
        vector<int> vec;

        while(ptr!=NULL){
            vec.push_back(ptr->val);
            ptr=ptr->next;
        }
        
        if(vec.empty()) return true;

        int i=0;
        int j=vec.size()-1;
        
        while(i<j){
            if(vec[i]!=vec[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
};

class Solution_TLE {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* ptr=head;
        string s1;
        string s2;
        while(ptr!=NULL){
            /*
            stringstream ss;
            ss << ptr->val;
            
            s1 = s1 + ss.str();
            s2 = ss.str() + s2;
            */
            s1=s1+to_string(ptr->val); //c++11 int to string
            s2=to_string(ptr->val)+s2;
            ptr=ptr->next;
        }
        
        if(s1.empty()||s2.empty()) return true;
        
        return s1==s2;
    }
};


int main(){
    
    return 0;
}