/*
Binary Tree Zigzag Level Order Traversal Total Accepted: 28968 Total Submissions: 109284 My Submissions Question Solution 
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/*
use queue to do BFS and set a flag node to mark each level.
if in queue it reach flag node. we push node vector into result vector

before push in result vector, we need handle reverse condition by reverse_flag. if it is true,
reverse tmp vector and push it in result vector.

for each level, flip reverse_flag.

*/



#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > out;
        vector<int> tmp;
        queue<TreeNode*> que;
        TreeNode* ptr;
        
        //INT_MAX is flag 
        TreeNode* flagNode=new TreeNode(INT_MAX); 
        
        if(root==NULL) return out;
        
        //set reverse_flag , if true, we need reverse tmp vector
        bool reverse_flag=false;

        //first push root and flagNode in queue
        que.push(root);
        que.push(flagNode);


        while(1){
            ptr=que.front();

             //if node in queue front is flag.
            //push tmp into out
            if(ptr->val==INT_MAX){
                //check reverse case;
                if(reverse_flag==true){
                    reverse(tmp.begin(),tmp.end());
                }
                que.pop();
                //handle last level
                if(que.empty()){
                    out.push_back(tmp);
                    tmp.clear();
                    break;
                }
                out.push_back(tmp);
                que.push(flagNode);             
                tmp.clear();

                //for each level, flip reverse_flag.
                reverse_flag=!reverse_flag;
            }else{
                //normal BFS
                tmp.push_back(ptr->val);
                
                if(ptr->left!=NULL)
                    que.push(ptr->left);
                if(ptr->right!=NULL)
                    que.push(ptr->right);
                que.pop();
            }
        }

        return out;
        
    }


};


int main(){
    TreeNode *root=new TreeNode(5);
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(3);
    TreeNode *c=new TreeNode(4);
    TreeNode *d=new TreeNode(6);
    TreeNode *e=new TreeNode(7);
    TreeNode *f=new TreeNode(9);
 
    root->left=b;
    root->right=e;
     
    b->left=a;
    b->right=c;
 
    e->left=d;
    e->right=f;

	Solution s;

    vector<vector<int> > out=s.zigzagLevelOrder(root);


    cout<<"results:"<<endl;
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<< out[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


	return 0;
}