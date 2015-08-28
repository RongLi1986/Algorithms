/*
Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/*
BFS+ reverse result
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
 * Definition for binary tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int> > out;
    	vector<int> tmp;
    	queue<TreeNode*> que;
    	TreeNode* ptr;
    	//this should be flag, INT_MAX is trick
    	TreeNode* flagNode=new TreeNode(INT_MAX); 
    	
    	if(root==NULL) return out;

    	que.push(root);
    	que.push(flagNode);


    	while(1){
    		ptr=que.front();
    		if(ptr->val==INT_MAX){
    			que.pop();
    			if(que.empty()){
    				out.push_back(tmp);
    				tmp.clear();
    				break;
    			}
    			out.push_back(tmp);
    			que.push(flagNode);   			
    			tmp.clear();
    		}else{
    			
	    		tmp.push_back(ptr->val);
	    		
	    		if(ptr->left!=NULL)
	    			que.push(ptr->left);
	    		if(ptr->right!=NULL)
	    			que.push(ptr->right);
	    		que.pop();
    		}
    	}

    	reverse(out.begin(),out.end());

    	return out;
        
    }


};


int main(){
	TreeNode* root=new TreeNode(1);
	TreeNode* a=new TreeNode(2);
	TreeNode* b=new TreeNode(3);
	TreeNode* c=new TreeNode(4);
	TreeNode* d=new TreeNode(5);
	root->left=a;
	root->right=b;
	b->left=c;
	c->right=d;
	
	Solution s;
	
	vector<vector<int> > out=s.levelOrderBottom(NULL);
	
	vector<vector<int> >::iterator itr1=out.begin();

	while(itr1!=out.end()){
		vector<int>::iterator itr2=(*itr1).begin();
		while(itr2!=(*itr1).end()){
			cout<<(*itr2)<<" ";
			itr2++;
		}
		cout<<endl;
		itr1++;
	}
	
	return 0;
}