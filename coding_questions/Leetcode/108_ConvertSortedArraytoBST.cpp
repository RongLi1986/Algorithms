/*
Convert Sorted Array to Binary Search Tree 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/


/*
use binary search on array,middle item is current TreeNode
left side will be Tree's left leaf, and right side will be Tree's right leaf
it could be done by using recursive
*/

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

//Definition for binary tree
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//rescurive solution
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode* root=buildTree(nums,0,nums.size()-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& nums,int start, int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* tmp=new TreeNode(nums[mid]);
        tmp->left=buildTree(nums,start,mid-1);
        tmp->right=buildTree(nums,mid+1,end);
        return tmp;
        
    }
};

/////old way
class Solution_old {
private:
	TreeNode *buildBst(vector<int> &num, int start, int end){
		int centerIndex=(end+start)/2;
		//cout<<centerIndex<<endl;
		TreeNode* root=new TreeNode(num[centerIndex]);
		if(start!=end){
			//cout<<start<<" "<<end<<endl;
			if(start!=centerIndex)  //for {1,2,3,4,5,6,7,8}
				root->left=buildBst(num,start,centerIndex-1);
			if(end!=centerIndex)
				root->right=buildBst(num,centerIndex+1,end);
		}

		return root;
	}
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	if(num.size()==0) return NULL;  //for []
        TreeNode* root=buildBst(num, 0,num.size()-1);
        return root;
    }
};




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

int main(){
	vector<int> num={1,2,3,4,5,6,7,8};
	Solution s;
	TreeNode* root=s.sortedArrayToBST(num);

	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) 
 		cout << i.next();

	return 0;
}