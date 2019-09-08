/*
Six Degrees

 Description
 Notes
 Testcase
 Judge
Six degrees of separation is the theory that everyone and everything is six or fewer steps away, by way of introduction, from any other person in the world, 
so that a chain of "a friend of a friend" statements can be made to connect any two people in a maximum of six steps.

Given a friendship relations, find the degrees of two people, return -1 if they can not been connected by friends of friends.

Have you met this question in a real interview? Yes
Example
Gien a graph:

1------2-----4
 \          /
  \        /
   \--3--/
{1,2,3#2,1,4#3,1,4#4,2,3} and s = 1, t = 4 return 2

Gien a graph:

1      2-----4
             /
           /
          3
{1#2,4#3,4#4,2,3} and s = 1, t = 4 return -1

*/

/*
bfs
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
     * @param graph a list of Undirected graph node
     * @param s, t two Undirected graph nodes
     * @return an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph,
                   UndirectedGraphNode* s,
                   UndirectedGraphNode* t) {
        // Write your code here
         unordered_map<UndirectedGraphNode*, int> visitMap; //node , int
         int count=-1;
         for(int i=0;i<graph.size();i++){
             if(graph[i]==s){
                count=GraphBFS(s, t,visitMap);
                return count;
             }
         }
         
         return count;
    }
    
    int GraphBFS(
        UndirectedGraphNode *node,
        UndirectedGraphNode *target,
        unordered_map<UndirectedGraphNode*, int> &visitMap)
    {
        deque<UndirectedGraphNode* > queue;
        UndirectedGraphNode* dumpNode=new UndirectedGraphNode(INT_MAX);
        queue.push_back(node);
        queue.push_back(dumpNode);
        int count = 0;
        visitMap[node] = 1;
        
        while(queue.size()>1){
            UndirectedGraphNode *head=queue.front();
            queue.pop_front();
            if(head->label==target->label){
                return count;
            }
            
            if(head->label==INT_MAX){
                count++;
                queue.push_back(head);
                continue;
            }
            vector<UndirectedGraphNode* > neighborList = head->neighbors;
            for(int i = 0; i < neighborList.size();i++){
                if(visitMap.find(neighborList[i])==visitMap.end()){
                    visitMap[neighborList[i]] = 1;
                    queue.push_back(neighborList[i]);
                }
            }
        }
        
        return -1;
    }

};