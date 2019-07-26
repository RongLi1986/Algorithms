/*
Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means?
*/

/*
use queue to do BFS and set a flag node to mark each level.
if in queue it reach flag node. we push node vector into result vector
*/



#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > out;
    	vector<int> tmp;
    	queue<TreeNode*> que;
    	TreeNode* ptr;

    	//INT_MAX is flag 
    	TreeNode* flagNode=new TreeNode(INT_MAX); 
    	
    	if(root==NULL) return out;

        //first push root and flagNode in queue
    	que.push(root);
    	que.push(flagNode);

    	while(1){
    		ptr=que.front();

            //if node in queue front is flag.
            //push tmp into out
    		if(ptr->val==INT_MAX){
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
	
	vector<vector<int> > out=s.levelOrder(root);
	
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


//other Solution
/*
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
       vector<vector<int> > ans; 
       dfsLevelOrder(root, 0, ans);
       return ans;
    }
private:
    void dfsLevelOrder(const TreeNode *root, int level, vector<vector<int> > & ans) const {
        if (root == nullptr)
            return;
        while (ans.size() <= level)
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        dfsLevelOrder(root->left, level + 1, ans);
        dfsLevelOrder(root->right, level + 1, ans);
    }
};
*/