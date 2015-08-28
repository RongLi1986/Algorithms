/* Maximum Depth of Binary Tree 

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

/*
DFS traversal
keep update max Depth value;
*/

/**
 * Definition for binary tree
*/
 #include <iostream>
 using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//DFS
class Solution {
private:
    int maxDep;
public:
    int maxDepth(TreeNode* root) {
        maxDep=0;
        DFS(root,0);
        
        return maxDep;
    }
    
    void DFS(TreeNode* root, int count){
        if(root==NULL){
            maxDep=max(count,maxDep);
            return;
        }
        
        count++;
        DFS(root->left,count);
        DFS(root->right,count);
        
        return;
    }
};


class Solution_old {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;

        return 1+max(maxDepth(root->left),maxDepth(root->right));

    }

    int max(int x,int y){
    	if(x>y)
    		return x;
    	else
    		return y;
    }
};

int main(){
	TreeNode* root=new TreeNode(0);
	TreeNode* a=new TreeNode(0);
	TreeNode* b=new TreeNode(0);
	TreeNode* c=new TreeNode(0);
	TreeNode* d=new TreeNode(0);
	root->left=a;
	root->right=b;
	b->left=c;
	c->right=d;

	Solution s;
	cout<<s.maxDepth(root)<<endl;

	return 0;
}