/*
CGraph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges 
make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/

/*
DFS
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int> >& edges) {
        vector<unordered_set<int> > g(n, unordered_set<int>());
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        for (auto a : edges) {
            g[a[0]].insert(a[1]);
            g[a[1]].insert(a[0]);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
    
    
};