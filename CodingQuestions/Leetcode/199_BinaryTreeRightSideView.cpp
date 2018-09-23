/*
Binary Tree Right Side View Total Accepted: 507 Total Submissions: 1891 My Submissions Question Solution 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/



/*
BFS level scan,
return last one (right side) for each level
*/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    deque<TreeNode*> heap;
public:
    vector<int> rightSideView(TreeNode *root) {
       vector<int> res;
       if(root==NULL) return res;
        
       TreeNode* mark=new TreeNode(INT_MAX);
       heap.push_back(root);
       heap.push_back(mark);
       TreeNode* lastOne=NULL;
       
       while(1){
           if(heap.front()->val==INT_MAX){ //we reach this level's end
               res.push_back(lastOne->val);
               if(heap.size()==1) break;
               heap.pop_front();
               heap.push_back(mark);
           }else{
               if(heap.front()->left!=NULL)
                heap.push_back(heap.front()->left);
               if(heap.front()->right!=NULL)
                heap.push_back(heap.front()->right);

                lastOne=heap.front();  //update lastOne Node
                heap.pop_front(); 
           }
       }
       
       return res;
    }
};


int main(){
	Solution s;
    TreeNode* root=new TreeNode(0);
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);

    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);

    root->left=a;
    root->right=b;

    a->left=c;
    a->right=d;

    b->left=e;


    vector<int> out=s.rightSideView(root);

    for(int i=0;i<out.size();i++){
        cout<<out[i]<<endl;
    }
	
	return 0;
}