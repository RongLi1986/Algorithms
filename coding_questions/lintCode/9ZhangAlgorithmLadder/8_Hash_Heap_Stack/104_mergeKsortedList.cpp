/*
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.
*/


/*
use a priority_queue, put all int into it running time (nlg(n))
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
*/
 
 struct cmp
{
    bool operator ()(const ListNode *a, const ListNode *b)
    {
            return a->val > b->val;
    }
};

class Solution {  //algorithms is right but slow AC
private:
    ListNode* head;
    priority_queue<ListNode*,vector<ListNode*>,cmp> que;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ptr=nullptr;
        head=nullptr;
        if(lists.empty()) return head;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr)
                que.push(lists[i]);
        }
        
        while(!que.empty()){
            if(head==nullptr){
                head=que.top();
                ListNode* tmp=que.top()->next;
                if(tmp!=nullptr) {
                    que.pop();
                    que.push(tmp);
                }else{
                    que.pop();
                }
                head->next=nullptr;
                ptr=head;
            }else{
                ptr->next=que.top();
                ListNode* tmp=que.top()->next;
                if(tmp!=nullptr) {
                    que.pop();
                    que.push(tmp);
                }else{
                    que.pop();
                }
                ptr=ptr->next;
                
            }
        }

        return head;
    }

    static bool way2Sort(ListNode* A, ListNode* B){
        return B->val<A->val;
    }

};