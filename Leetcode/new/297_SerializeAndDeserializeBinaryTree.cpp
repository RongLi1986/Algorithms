/*
Serialize and Deserialize Binary Tree My Submissions Question
Total Accepted: 6838 Total Submissions: 27965 Difficulty: Medium
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
how to decide a tree by one string???
I think it at least needs two strings

one is inorder and another is postorder
*/


#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        //TreeNode* nullNode=NULL;
        while(!queue.empty()){
            TreeNode* node=queue.front();

            if(node==NULL){
                return res;
            }else{
                res+=to_string(node->val);
                
                if(node->left){ 
                    res+="L";
                    queue.push_back(node->left);
                }

                if(node->right){
                    res+="R";
                    queue.push_back(node->right);
                }
                
                res+=",";
            }
            
            queue.pop_front();
        
        }
        
        return res;
    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        //cout<<data<<endl;
        deque<TreeNode* > queue;
        
        int index=0;  //push 0 in queue before loop
        deque<int> flagQueue;  //0 is no leafs, 1 is left, 2 is right, 3 is both
        
        //find nums string
        int i=index;
        while(data[i]!=','){
            i++;
        }

        string nums=data.substr(index,i-index);
        int flag=checkLeap(nums);

        index=i;    
        TreeNode* root;

        if(flag==0){
            root=new TreeNode(stoi(nums));
        }else if(flag==1){
            root=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
        }else if(flag==2){
            root=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
        }else{
            root=new TreeNode(stoi(nums.substr(0,nums.size()-2)));
        }

        index++;
        queue.push_back(root);
        flagQueue.push_back(flag);

        while(!queue.empty()){
            TreeNode* ptr=queue.front();
            int flag=flagQueue.front();

            if(flag==0){ //no leap
            //do nothing    
            }else if(flag==1){ //left
                //left
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                string nums=data.substr(index,i-index);
                int flag=checkLeap(nums);
                TreeNode* node;
                if(flag==0){
                    node=new TreeNode(stoi(nums));
                }else if(flag==1){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else if(flag==2){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else{
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-2)));
                }

                ptr->left=node;
                queue.push_back(node);
                flagQueue.push_back(flag);

                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
                index++;
            }else if(flag==2){  //right
                //left
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                string nums=data.substr(index,i-index);
                int flag=checkLeap(nums);
                TreeNode* node;
                if(flag==0){
                    node=new TreeNode(stoi(nums));
                }else if(flag==1){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else if(flag==2){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else{
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-2)));
                }

                ptr->right=node;
                queue.push_back(node);
                flagQueue.push_back(flag);

                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
                index++;
            }else{ //left +right
                
                //left
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                string nums=data.substr(index,i-index);
                int flag=checkLeap(nums);
                TreeNode* node;
                if(flag==0){
                    node=new TreeNode(stoi(nums));
                }else if(flag==1){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else if(flag==2){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else{
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-2)));
                }

                ptr->left=node;
                queue.push_back(node);
                flagQueue.push_back(flag);

                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
                index++;

                //right
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                
                nums=data.substr(index,i-index);
                flag=checkLeap(nums);
                
                if(flag==0){
                    node=new TreeNode(stoi(nums));
                }else if(flag==1){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else if(flag==2){
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-1)));
                }else{
                    node=new TreeNode(stoi(nums.substr(0,nums.size()-2)));
                }

                ptr->right=node;
                queue.push_back(node);
                flagQueue.push_back(flag);

                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
                index++;
                
            }            

            queue.pop_front();
            flagQueue.pop_front();
        }

        
        return root;    
    }

    int checkLeap(string& s){
        if(s.size()<=1) return 0;
        char s1=s[s.size()-2];
        char s2=s[s.size()-1];

        if(s1=='L'&& s2=='R'){
            //s=s.substr(0,s.size()-2);
            return 3;
        }else if(s2=='L'){
            //s=s.substr(0,s.size()-1);
            return 1;
        }else if(s2=='R'){
            //s=s.substr(0,s.size()-1);
            return 2;
        }else{
            return 0;
        }
    }
};



//TLE
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //find tree's height
        //cout<<"bp"<<endl;
        int level=findTreeHeight(root,0);
        int nodeCount=pow(2,level)-1;
        cout<<nodeCount<<endl;
        //BFS build string
        int i=0; //control tree level
        int j=0; //control string item
        string res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        TreeNode* nullNode=NULL;
        while(i<nodeCount){
            TreeNode* node=queue.front();
        
            if(node==NULL){
                //cout<<"bp"<<endl;
                res+="#";
                res+=",";
                queue.push_back(nullNode);
                queue.push_back(nullNode);
            }else{
                res+=to_string(node->val);
                res+=",";
                queue.push_back(node->left);
                queue.push_back(node->right);
            }
            
            queue.pop_front();
            
            i++;
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        //cout<<data<<endl;
        
        deque<TreeNode* > queue;
        
        int index=0;  //push 0 in queue before loop

        //find nums string
        int i=index;
        while(data[i]!=','){
            i++;
        }
        string nums=data.substr(index,i-index);

        //cout<<index<<" "<<i<<" "<<nums<<endl;
        index=i;    
        
        TreeNode* root=new TreeNode(stoi(nums));
        
        index++;
        queue.push_back(root);
        
        while(index<data.size()){
            //cout<<index<<endl;
            TreeNode* ptr=queue.front();
            

            if(ptr->val!=INT_MAX){
                //connect left node
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                string nums=data.substr(index,i-index);
                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
                    
                //conect left node    
                if(nums=="#"){ //NULL node
                    TreeNode* node=new TreeNode(INT_MAX);
                    queue.push_back(node);
                    index++;
                }else{
                    
                    TreeNode* node=new TreeNode(stoi(nums));
                    queue.push_back(node);
                    ptr->left=node;
                    index++;
                }
                
                i=index;
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                nums=data.substr(index,i-index);
                //cout<<index<<" "<<i<<" "<<nums<<endl;
                index=i;
            
                //connect right node
                if(nums=="#"){ //NULL node
                    TreeNode* node=new TreeNode(INT_MAX);
                    queue.push_back(node);
                    index++;
                }else{
                    TreeNode* node=new TreeNode(stoi(nums));
                    
                    queue.push_back(node);
                    ptr->right=node;
                    index++;
                }            
            }else{
                index++;
                i=index;
                
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                //if(index==2047)  cout<<"bb: "<<i<<endl;
                index=i;
                
                //cout<<index <<" : "<<data[index]<<endl;
                TreeNode* node=new TreeNode(INT_MAX);
                queue.push_back(node);
                index++;
                
                i=index;
                
                
                if(i>=data.size()) break;
                while(data[i]!=','){
                    i++;
                }
                index=i;
                
                
                queue.push_back(node);    
                
                index++;
            }
            
            queue.pop_front();

        }
        
        return root;
    }
    
    
    
    int findTreeHeight(TreeNode* root, int level){
        if(root==0){
            return level;
        }else{
            level++;
            return max(findTreeHeight(root->left, level),findTreeHeight(root->right,level));

        }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(){
    
    return 0;
}