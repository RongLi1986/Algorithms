/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

How we serialize an undirected graph:

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
DFS
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copyMap; //old node , new node
        
        UndirectedGraphNode* copyNode = cloneGraphDFS(node, copyMap);
        
        return copyNode;
    }
    
    
    UndirectedGraphNode* cloneGraphDFS(
        UndirectedGraphNode *node, 
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &copyMap)
    {
        if(node==NULL)
            return NULL;
        
        UndirectedGraphNode* returnNode = new UndirectedGraphNode(node->label);
        copyMap[node] = returnNode;
        vector<UndirectedGraphNode* > neighborList = node->neighbors;
        for(int i = 0; i < neighborList.size();i++){
            if(copyMap.find(neighborList[i])==copyMap.end()){
                UndirectedGraphNode* copyneighborNode=cloneGraphDFS(neighborList[i],copyMap);
                (returnNode->neighbors).push_back(copyneighborNode);
            }else{
                (returnNode->neighbors).push_back(copyMap[neighborList[i]]);
            }
        }
        
        return returnNode;
    }
};