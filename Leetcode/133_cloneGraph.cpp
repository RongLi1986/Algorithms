/*
Clone Graph 
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */

/*
this solution is base on BFS and Haspmap
first bfs original nodes, and create copy nodes. 
do original and copy nodes' mapping  in hashmap

second bfs, find each copy nodes neighbor from hasmap.
and connect their bridge
*/



#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;


/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//base on BFS AND hashmap
class Solution {
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> myMap; //original ptr, copy ptr
    UndirectedGraphNode* root;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        root=NULL;
        BFS(node,0);
        BFS(node,1);
        
        return root;
    }

    void BFS(UndirectedGraphNode *node, int flag){
        if(node==NULL) return;
        queue<UndirectedGraphNode*> que;
        unordered_set<UndirectedGraphNode*> visit;
        
        que.push(node);
        visit.insert(node);
        
        while(!que.empty()){
            //get front node
            UndirectedGraphNode* tmp=que.front();
            que.pop();
                    
            //build hash map for original node and copy node
            if(flag==0){
                UndirectedGraphNode* copyNode=new UndirectedGraphNode(tmp->label);
                if(root==NULL) root=copyNode;
                myMap[tmp]=copyNode;
            }
            
            for(int i=0;i<tmp->neighbors.size();i++){
                if(flag==0){ //only BFS original nodes
                
                    //tricky part:it must update visit set in here
                    //not visited
                    if(visit.find(tmp->neighbors[i])==visit.end()){
                        que.push(tmp->neighbors[i]);
                        visit.insert(tmp->neighbors[i]);
                    }
                }else{//BFS original nodes, and build bridge for copy nodes
                    UndirectedGraphNode* ptr=myMap[tmp]; //find copy node
                    ptr->neighbors.push_back(myMap[tmp->neighbors[i]]); //build bridge
                    
                    //tricky part:it must update visit set in here
                    if(visit.find(tmp->neighbors[i])==visit.end()){
                        que.push(tmp->neighbors[i]);
                        visit.insert(tmp->neighbors[i]);
                    }
                }
            }
        }
        
        return;
    }
};



/*
class Solution {
private:
    map<int,UndirectedGraphNode*> visitedMap;
    map<int,UndirectedGraphNode*> visitedMap1;
    deque<UndirectedGraphNode*> queue;
    UndirectedGraphNode* out;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //BFS
        out=nullptr;
        if(node==nullptr) return out;
        queue.push_back(node);
        visitedMap[node->label]=node;
        while(!queue.empty()){
            cout<<"ll "<<queue.front()->label<<endl;
            
            UndirectedGraphNode *cloneNode=new UndirectedGraphNode(queue.front()->label);
            visitedMap1[cloneNode->label]=cloneNode;
            
            cout<<"clone"<<cloneNode->label<<endl;
            for(int i=0;i<(queue.front()->neighbors).size();i++){
                cout<<queue.front()->neighbors[i]->label<<" ";
                if(visitedMap[queue.front()->neighbors[i]->label] == NULL){
                    cout<<"push";//<<queue.front()->neighbors[i]->label<<" ";
                    queue.push_back(queue.front()->neighbors[i]);
                    visitedMap[queue.front()->neighbors[i]->label]=queue.front()->neighbors[i];
                    UndirectedGraphNode *cloneNode1=new UndirectedGraphNode(queue.front()->neighbors[i]->label);
                    (cloneNode->neighbors).push_back(cloneNode1); 
                    visitedMap1[cloneNode1->label]=cloneNode1;

                }else{
                    cout<<"clone";
                    (cloneNode->neighbors).push_back( visitedMap1[queue.front()->neighbors[i]->label]); 
                }
                cout<<endl;
                
            }
            //cout<<endl;
            if(out==nullptr) out=cloneNode;
            
            queue.pop_front();
        }

        //if(node!=out) cout<<"hh"<<endl;

        return out;
    }

};
*/
class Solution_old {
private:
    map<int,UndirectedGraphNode*> visitedMap;
    map<int,UndirectedGraphNode*> visitedMap1;
    deque<UndirectedGraphNode*> queue;
    UndirectedGraphNode* out;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //BFS
        out=nullptr;
        if(node==nullptr) return out;
        //1 build copy Node
        queue.push_back(node);
        visitedMap[node->label]=node;
        while(!queue.empty()){
            //cout<<"ll "<<queue.front()->label<<endl;
            
            UndirectedGraphNode *cloneNode=new UndirectedGraphNode(queue.front()->label);
            visitedMap1[cloneNode->label]=cloneNode;
            
            //cout<<"clone"<<cloneNode->label<<endl;
            for(int i=0;i<(queue.front()->neighbors).size();i++){
                //cout<<queue.front()->neighbors[i]->label<<" ";
                if(visitedMap[queue.front()->neighbors[i]->label] == NULL){
                   // cout<<"push";//<<queue.front()->neighbors[i]->label<<" ";
                    queue.push_back(queue.front()->neighbors[i]);
                    visitedMap[queue.front()->neighbors[i]->label]=queue.front()->neighbors[i];
                    //UndirectedGraphNode *cloneNode1=new UndirectedGraphNode(queue.front()->neighbors[i]->label);
                    //(cloneNode->neighbors).push_back(cloneNode1); 
                    //visitedMap1[cloneNode1->label]=cloneNode1;
                }
                
                //cout<<endl;
                
            }   

            if(out==nullptr) out=cloneNode;
            queue.pop_front();
        }

        visitedMap.clear();

        //2 build edge
        queue.push_back(node);
        visitedMap[node->label]=node;
        while(!queue.empty()){
            for(int i=0;i<(queue.front()->neighbors).size();i++){
                visitedMap1[queue.front()->label]->neighbors.push_back(visitedMap1[queue.front()->neighbors[i]->label]);
                if(visitedMap[queue.front()->neighbors[i]->label] == NULL){
                    queue.push_back(queue.front()->neighbors[i]);
                    visitedMap[queue.front()->neighbors[i]->label]=queue.front()->neighbors[i];
                }
                
                //cout<<endl;
                
            }            
            queue.pop_front();
        }


        return out;
    }

};

void BFS_print(UndirectedGraphNode *node){
    set<UndirectedGraphNode*> vistedMap;
    deque<UndirectedGraphNode*> queue;
    queue.push_back(node);
    vistedMap.insert(node);
    while(!queue.empty()){
        cout<<queue.front()<< " label: "<<queue.front()->label<<" neighbors:";
        for(int i=0;i<(queue.front()->neighbors).size();i++){
            cout<<queue.front()->neighbors[i]<<" ";
            if(vistedMap.find(queue.front()->neighbors[i]) == vistedMap.end()){
                //cout<<"push "<<queue.front()->neighbors[i]->label<<" ";
                queue.push_back(queue.front()->neighbors[i]);
                vistedMap.insert(queue.front()->neighbors[i]);
            }
        }
        cout<<endl;
        queue.pop_front();
    }
}

int main(){
    UndirectedGraphNode* a=new UndirectedGraphNode(0);
    UndirectedGraphNode* b=new UndirectedGraphNode(1);
    UndirectedGraphNode* c=new UndirectedGraphNode(2);
    
    a->neighbors.push_back(a);
    a->neighbors.push_back(a);
    
    /*
    a->neighbors.push_back(b);
    a->neighbors.push_back(c);

    b->neighbors.push_back(a);
    b->neighbors.push_back(c);

    c->neighbors.push_back(c);
    c->neighbors.push_back(a);
    */
    Solution s;
    UndirectedGraphNode* out=s.cloneGraph(a);
    BFS_print(out);
	return 0;
}