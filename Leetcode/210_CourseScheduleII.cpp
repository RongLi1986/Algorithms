/*
Course Schedule II 
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3].
Another correct ordering is[0,2,1,3].
*/


/*
this question is find whether it has a cycle in graph

Toposort
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)
*/


#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <utility>      // std::pair
#include <algorithm>
 
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
    vector<int> out;  //save path
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

}
 
void Graph::addEdge(int v, int w)
{    
    adj[w].push_back(v); // Add w to v’s list.
}
 
// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    //cout<<v<<endl;
    if(visited[v] == false)
    {   
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ){
                return true;
            }
            else if (recStack[*i])
                return true;
        }
    }
    
    int flag=0;
    for(int i=0;i<out.size();i++){
            if(out[i]==v)
                flag=1;
    }

    if(flag==0)
        out.push_back(v);


    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}





class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        
        Graph* g=new Graph(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            //cout<<prerequisites[i].first<<prerequisites[i].second<<endl;
            g->addEdge(prerequisites[i].first, prerequisites[i].second);
        }

        vector<int> out1;
        if(g->isCyclic())
            return out1;
        else{
            out1=g->out;
            reverse(out1.begin(),out1.end());
            return out1;
        }
    }
};

int main(){
    pair<int,int> edge, edge1,edge2,edge3,edge4;
    edge=make_pair(1,0);
    edge1=make_pair(1,2);
    edge2=make_pair(2,4);
    edge3=make_pair(3,4);
    edge4=make_pair(4,5);


    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(edge);
    prerequisites.push_back(edge1);
    //prerequisites.push_back(edge2);
    //prerequisites.push_back(edge3);
    //prerequisites.push_back(edge4);


    int numCourses=3;

    Solution s;
    vector<int> out=s.findOrder(numCourses,prerequisites);


    
    for(int i=0;i<out.size();i++)
        cout<<out[i]<<" ";
    cout<<endl;
    
    return 0;
}