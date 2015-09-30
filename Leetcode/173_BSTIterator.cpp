/*
Binary Search Tree Iterator Total Accepted: 11081 Total Submissions: 38271 My Submissions Question Solution 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/


/*
scan tree and push each item into queue,
then sort it.

Running time is O(nlgn)

*/


#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//recursive DFS and no need sort queue
class BSTIterator {
private:
    vector<int> queue;
    int NextPtr;
    void pushInSatck(TreeNode *root){
        if(root!=NULL){
            pushInSatck(root->left);
            queue.push_back(root->val);
            pushInSatck(root->right);
        }
    }

public:
    BSTIterator(TreeNode *root) {
        pushInSatck(root);
        
        if(!queue.empty()){
            NextPtr=0;
        }else
            NextPtr=INT_MAX;
        //sort(stack.begin(), stack.end());
        //reverse(stack.begin(), stack.end());
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return NextPtr<queue.size();
    }

    /** @return the next smallest number */
    int next() {
        int tmp=NextPtr;
        NextPtr++;
        return queue[tmp];
    }
};

//it use only stack
class BSTIterator {
private:
	vector<int> stack;

	void pushInSatck(TreeNode *root){
		if(root!=NULL){
        	stack.push_back(root->val);
        	pushInSatck(root->left);
        	pushInSatck(root->right);
        }
	}

public:
    BSTIterator(TreeNode *root) {
        pushInSatck(root);

        sort(stack.begin(), stack.end());
        reverse(stack.begin(), stack.end());
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(stack.size()!=0)
        	return true;
        else
        	return false;
    }

    /** @return the next smallest number */
    int next() {
        int tmp=stack.back();
        stack.pop_back();
        return tmp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

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

 	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) 
 		cout << i.next();

 	return 0;
 }