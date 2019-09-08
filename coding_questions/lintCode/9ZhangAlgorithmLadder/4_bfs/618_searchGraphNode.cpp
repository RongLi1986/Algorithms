/*
Given a undirected graph, a node and a target, return the nearest node to given node which value of it is target, return NULL if you can't find.

There is a mapping store the nodes' values in the given parameters.

 Notice

It's guaranteed there is only one available solution

Have you met this question in a real interview? Yes
Example
2------3  5
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      1 --4
Give a node 1, target is 50

there a hash named values which is [3,4,10,50,50], represent:
Value of node 1 is 3
Value of node 2 is 4
Value of node 3 is 10
Value of node 4 is 50
Value of node 5 is 50

Return node 4
*/

/*
bfs
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
//bfs
class Solution {
public:
    /**
     * @param graph a list of Undirected graph node
     * @param values a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node an Undirected graph node
     * @param target an integer
     * @return the a node
     */
    UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // Write your code here
        if(values[node] == target)
            return node;
        
        unordered_map<UndirectedGraphNode*, int> visitMap;
        deque<UndirectedGraphNode* > queue;
        queue.push_back(node);
        
        while(!queue.empty()){
            UndirectedGraphNode* ptr = queue.front();
            queue.pop_front();
            
            for(int i=0;i<ptr->neighbors.size();i++){
                if(visitMap.find(ptr->neighbors[i]) == visitMap.end()){
                    if(values[ptr->neighbors[i]] == target) 
                        return ptr->neighbors[i];
                    
                    visitMap[ptr->neighbors[i]] == 1;
                    queue.push_back(ptr->neighbors[i]);
                }
            }
        }
        
        return NULL;
    }
};