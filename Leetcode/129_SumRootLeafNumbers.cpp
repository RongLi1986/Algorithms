/*
Sum Root to Leaf Numbers 
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/*
use recursive and DFS, caculate each leaf value,
when node is end, update sum.
*/



#include <iostream>
using namespace std;
/**
 * Definition for binary tree
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    int sum;
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        sum=0;
        dfs(root,0);
        
        return sum;//accumulate(sum.begin(),sum.end(),0);
    }
    
    void dfs(TreeNode* root,int tmp){
        tmp*=10;
        tmp+=root->val;
        
        if(root->left!=NULL)
            dfs(root->left,tmp);
        if(root->right!=NULL)
            dfs(root->right,tmp);
        
        //if it is last node, push result into vector
        //it cannot do at leaf, because it has left and right(result will double)
        if(root->left==NULL&&root->right==NULL)
            sum+=tmp;
    
        return;
    }
};


class Solution_old {
public:
    int sumNumbers(TreeNode *root) {
 		return sumNumbersRe(root, 0);
    }

    int sumNumbersRe(TreeNode* root, int sumLastLevel){
    	if(root==NULL) return sumLastLevel;
    	sumLastLevel=root->val+sumLastLevel;

    	if(root->left==NULL&&root->right==NULL)
    		return sumLastLevel;

    	sumLastLevel*=10;
    	int left=0;
    	int right=0;
    	if(root->left!=NULL)
    		left=sumNumbersRe(root->left,sumLastLevel);

    	if(root->right!=NULL)
    		right=sumNumbersRe(root->right,sumLastLevel);

    	return right+left;
    }
};

int main(){
	TreeNode* root=new TreeNode(1);
	TreeNode* a=new TreeNode(2);
	TreeNode* b=new TreeNode(3);
	root->left=a;
	root->right=b;
	Solution s;
	cout<<s.sumNumbers(root)<<endl;;


	return 0;
}