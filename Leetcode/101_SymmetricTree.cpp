/*
Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/


/*
two ways:
1. compare recursively.
2. use post order and in order traverse tree and put node in array.
then, compare two array is same or not.
*/



#include <iostream>
#include <vector>
#include <climits>
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
public:
    bool isSymmetric(TreeNode *root){
    	return check(root,root); 
    }

    bool check(TreeNode *root1,TreeNode *root2){
    	if(root1==NULL&&root2==NULL)
    		return true;
    	else if (root1==NULL||root2==NULL){
    		return false;
    	}else{
    		if(root1->val!=root2->val){
    			return false;
    		}else{
    			return check(root1->left,root2->right)&&check(root1->right,root2->left);
    		}
    	}
    }
};

class Solution1 {
private:
	vector<int> vectLtR;
	vector<int> vectRtL;
public:
	void pushLtR(TreeNode *root){
		if(root!=NULL){
			vectLtR.push_back(root->val);
			pushLtR(root->left);
			pushLtR(root->right);
		}else{
			vectLtR.push_back(INT_MAX);
		}
	}

	void  pushRtL(TreeNode* root){
		if(root!=NULL){
			vectRtL.push_back(root->val);
			pushRtL(root->right);
			pushRtL(root->left);
		}else{
			vectRtL.push_back(INT_MAX);
		}
	}

    bool isSymmetric(TreeNode *root){
		pushRtL(root);
		pushLtR(root);
		//cout<<vectRtL.size()<<endl;
		if(vectRtL.size()==vectLtR.size()){
			for(int i=0;i<vectRtL.size();i++){
				if(vectRtL[i]!=vectLtR[i])
					return false;
			}

			return true;
		}  	

		return false;
  	}
};


int main(){
	Solution s;
	cout<<s.isSymmetric(NULL)<<endl;  
	return 0;
}