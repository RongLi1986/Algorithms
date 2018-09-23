/*
Convert Sorted List to Binary Search Tree 
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
this question is similar with last one, convert array to BST
so we could build a vector by list.
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


//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

//basicly, it change list to array
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums=convertListToVector(head);
        TreeNode* root=sortedArrayToBST(nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=buildTree(nums,0,nums.size()-1);
        return root;
    }
    
    vector<int> convertListToVector(ListNode* head){
        ListNode* ptr=head;
        vector<int> out;
        while(ptr!=NULL){
            out.push_back(ptr->val);
            ptr=ptr->next;
        }
        
        return out;
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





//old sol
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

class Solution_old {
private:
    void changeListtoArray(ListNode* head, vector<int> &num){
        ListNode* ptr=head;
        while(ptr!=NULL){
            //cout<<ptr->val<<endl;
            num.push_back(ptr->val);
            ptr=ptr->next;
        }

    }

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
    TreeNode *sortedListToBST(ListNode *head) {
    	if(head==NULL) return NULL;  //for []
        
        vector<int> num;
        changeListtoArray(head,num);

        TreeNode* root=buildBst(num, 0,num.size()-1);
        return root;
    }
};

int main(){
    ListNode* head=new ListNode(1);

    ListNode* a=new ListNode(2);
    ListNode* b=new ListNode(3);
    ListNode* c=new ListNode(4);
    ListNode* d=new ListNode(5);
    ListNode* e=new ListNode(6);
    ListNode* f=new ListNode(7);

    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;

	Solution s;
	TreeNode* root=s.sortedListToBST(head);

	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) 
 		cout << i.next();

	return 0;
}