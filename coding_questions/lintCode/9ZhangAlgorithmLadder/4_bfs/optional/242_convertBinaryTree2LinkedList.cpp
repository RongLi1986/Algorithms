/*
Convert Binary Tree to Linked Lists by Depth

Given a binary tree, design an algorithm which creates a linked list of all the 
nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked 
lists).

Have you met this question in a real interview? Yes
Example
Given binary tree:

    1
   / \
  2   3
 /
4
return

[
  1->null,
  2->3->null,
  4->null
]
*/

/*

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
private:
    vector<vector<int> > res; 
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        levelOrder(root);
        vector<ListNode* > ans;
        
        for(int i = 0;i<res.size();i++){
            ListNode* head;
            ListNode* tail;
            for(int j = 0;j<res[i].size();j++){
                ListNode* node = new ListNode(res[i][j]);
                if(j==0){
                    head = node;
                    tail = node;
                    ans.push_back(head);
                }else{
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
        
        return ans;
    }

    void levelOrder(TreeNode *root) {
        // write your code here
        if(root==NULL) return;
        
        TreeNode* dummyNode = new TreeNode(INT_MAX);
        
        deque<TreeNode*> queue;
        vector<int> level;
        queue.push_back(root);
        queue.push_back(dummyNode);
        
        while(1){
            TreeNode* tmp=queue.front();
            //cout<<tmp->val<<endl;
            if(tmp->val==INT_MAX){ //level end
                res.push_back(level);
                level.clear();
                queue.pop_front();
                queue.push_back(dummyNode);
                if(queue.size()==1) //only dummy node, leave loop
                    break;
            }else{                  //normal nodes
                level.push_back(tmp->val);
                if(tmp->left)
                    queue.push_back(tmp->left);
                if(tmp->right)
                    queue.push_back(tmp->right);
                queue.pop_front();
            }
        }
        
        delete dummyNode;
        
        return;
    }
};
