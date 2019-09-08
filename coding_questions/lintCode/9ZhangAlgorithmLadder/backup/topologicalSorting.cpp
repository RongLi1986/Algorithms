/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

 Notice

You can assume that there is at least one topological order in the graph.


Clarification
Learn more about representation of graphs

*/

/*
DFS
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode* > res;
        stack<DirectedGraphNode*> stk;
        unordered_map<DirectedGraphNode*, int> visitedMap;
        
        for(int i=0; i<graph.size();i++){
            //DirectedGraphNode* tmpNode = graph[i];
            if(visitedMap.find(graph[i])==visitedMap.end()){
                topologicalSortUtil(graph[i], visitedMap, stk);
            }
            
        }
        
        // push contents of stack to result
        while (stk.empty() == false)
        {
            //cout << Stack.top() << " ";
            res.push_back(stk.top());
            stk.pop();
        }
        
        return res;
    }
    
    void topologicalSortUtil(DirectedGraphNode* graphNode, 
                            unordered_map<DirectedGraphNode*, int> &visitedMap,
                            stack<DirectedGraphNode*> &stk)
    {
        // Mark the current node as visited.
        visitedMap[graphNode] = 1;
     
        // Recur for all the vertices adjacent to this vertex
        vector<DirectedGraphNode *> neighborsList=graphNode->neighbors;
        for(int i=0;i<neighborsList.size();i++)
            if (visitedMap.find(neighborsList[i])==visitedMap.end())
                topologicalSortUtil(neighborsList[i], visitedMap, stk);
     
        // Push current vertex to stack which stores result
        stk.push(graphNode);                        
                            
        return;
    }
};