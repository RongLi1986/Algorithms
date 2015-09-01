/*
Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

/*
same with last question..
similar with question about BFS level traversal binary Tree
use Queue and a endNode to mark each level
connecting nodes' NextRightPointer which in same level
*/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//this idea is clear
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        //we do BFS with queue
        TreeLinkNode* endNode=new TreeLinkNode(INT_MAX);
        queue<TreeLinkNode*> que;
        
        que.push(root);
        que.push(endNode);
        
        while(1){
            //drop queue's first node
            TreeLinkNode* front=que.front();
            que.pop();

            
            if(front->val==INT_MAX){ //this is endNode
                if(que.empty())//break 
                    break;
                else{
                    //let put endNode back to queue, it will be next end mark
                    que.push(front);
                }
            }else{
                //connection is here
                if(que.front()->val!=INT_MAX){
                    front->next=que.front();
                }
                
                // front node's left and right children into queue
                if(front->left!=NULL)
                    que.push(front->left);
                
                if(front->right!=NULL)
                    que.push(front->right);
                
            }
        }
    
        return;
    }
};


class Solution_old {
private:
    deque<TreeLinkNode*> queue;
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* endNode=new TreeLinkNode(INT_MAX);
        TreeLinkNode* preTreeLinkNode=NULL;
        if(root==NULL) return;
        queue.push_back(root);
        queue.push_back(endNode);

        while(queue.size()!=0){
            if(queue.front()->val==INT_MAX){

                if(queue.size()==1) break;
                
                queue.push_back(endNode);
                
                queue.pop_front();
                
                preTreeLinkNode=NULL;
                //if(preTreeLinkNode!=NULL)
                  //  preTreeLinkNode=queue.front();

            }else{

                if(preTreeLinkNode!=NULL)
                    preTreeLinkNode->next=queue.front();
                //cout<<queue.front()->val<<endl;
                
                if(queue.front()->left!=NULL){
                    queue.push_back(queue.front()->left);
                }

                if(queue.front()->right!=NULL){
                    queue.push_back(queue.front()->right);
                }   

                preTreeLinkNode=queue.front();

                queue.pop_front();        
            }
        }
    }
};


int main(){
    TreeLinkNode *root=new TreeLinkNode(5);
    TreeLinkNode *a=new TreeLinkNode(1);
    TreeLinkNode *b=new TreeLinkNode(3);
    TreeLinkNode *c=new TreeLinkNode(4);
    TreeLinkNode *d=new TreeLinkNode(6);
    TreeLinkNode *e=new TreeLinkNode(7);
    TreeLinkNode *f=new TreeLinkNode(9);
 
    root->left=b;
    //root->right=e;
     
    //b->left=a;
    //b->right=c;
 
    //e->left=d;
    //e->right=f;

	Solution s;

    s.connect(root);


    cout<<"results:"<<endl;
    TreeLinkNode* ptr=b;
    if(ptr->next!=NULL)
        cout<< ptr->next->val <<endl;
    else
        cout<<"NULL"<<endl;

	return 0;
}


/*  good sol only for perfect tree
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            root->left->next = root->right;
            if(root->next!=nullptr){
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
    }
};
*/