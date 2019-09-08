/*
GConnected Component in Undirected Graph

Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. 
(a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, 
and which is connected to no additional vertices in the supergraph.)

Clarification
Learn more about representation of graphs

Example
Given graph:

A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
*/

/*

*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
private:
    vector<vector<int> > res;
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_map<UndirectedGraphNode*, int> visitMap; //old node , new node
        vector<int> tmp;
        for(int i=0;i<nodes.size();i++){
            if(visitMap.find(nodes[i])==visitMap.end())
                GraphBFS(nodes[i], tmp, visitMap);
        }
        
        return res;
    }
    
    void GraphBFS(
        UndirectedGraphNode *node,
        vector<int> tmp,
        unordered_map<UndirectedGraphNode*, int> &visitMap)
    {
        deque<UndirectedGraphNode* > queue;
        queue.push_back(node);
        visitMap[node] = 1;
        tmp.push_back(node->label);
        
        while(!queue.empty()){
            UndirectedGraphNode *head=queue.front();
            queue.pop_front();
            vector<UndirectedGraphNode* > neighborList = head->neighbors;
            for(int i = 0; i < neighborList.size();i++){
                if(visitMap.find(neighborList[i])==visitMap.end()){
                    visitMap[neighborList[i]] = 1;
                    tmp.push_back(neighborList[i]->label);
                    queue.push_back(neighborList[i]);
                }
            }
        }
        
        sort(tmp.begin(),tmp.end());
        res.push_back(tmp);
        
        return;
    }
};