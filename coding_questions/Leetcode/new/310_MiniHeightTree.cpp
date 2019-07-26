/*
310. Minimum Height Trees   My Submissions QuestionEditorial Solution
Total Accepted: 11071 Total Submissions: 41666 Difficulty: Medium
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?
Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Credits:
Sp
 */

/*
caculate each node's degree.
and put them  whose degree is 1 into a queue.
then for each node in this queue, decrease 1 degree to any node which connect to it.
And put new node whose degree is 1 into queue. keep doing it until there are only one or two node left.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};  //corner case
        vector<vector<int>> map(n,vector<int>());
        vector<int> degree(n,0);
        deque<int> queue;
        vector<int> res;
        
        for(int i=0; i<edges.size();++i){
            map[edges[i].first].push_back(edges[i].second);
            degree[edges[i].second]++;
            
            map[edges[i].second].push_back(edges[i].first);
            degree[edges[i].first]++;
        }
        
        /*
        for(int i=0;i<degree.size();i++){
            cout<<degree[i]<<" ";
        }
        cout<<endl;
        */
       
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) queue.push_back(i);
        }
        
        while(n>2){
            //cout<<queue.front()<<" ";
            int sz=queue.size();
            
            for(int j=0;j<sz;j++){
                
                
                int t=queue.front();
                
                for(int i=0;i<map[t].size();i++){
                    //cout<<map[queue.front()][i]<<" ";
                    degree[map[queue.front()][i]]-=1;
                    if(degree[map[queue.front()][i]]==1)
                        queue.push_back(map[queue.front()][i]);
                }
                
                queue.pop_front();
                n--;
                
            }
            //cout<<endl;
            
        }
        
        while(!queue.empty()){
            res.push_back(queue.front());
            queue.pop_front();
        }
        
        return res;
    }
};

int main(){

    return 0;
}