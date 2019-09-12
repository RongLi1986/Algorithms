/*******************************************************
 Find the Connected Component in the Undirected Graph

 A<-->B<-->C
 D<-->E

 return [A, B, C], [D, E]

********************************************************/


/*
UnionFind
O(V+E)
*/ 

class UnionFind
{
private:
    unordered_map<int, int> parent;

public:
    UnionFind(){
        
    };

    UnionFind(unordered_set<int>& items){
        for (auto item : items){
            parent[item] = item;
        }
    }

    int find(int x){
        int p = x;
        while(p != parent[p]){
            p = parent[p]
        }
        return p;
    }

    void union(int x, int y){
        int f_x = find(x);
        int f_y = find(y);
        if(f_x != f_y){
            parent[f_x] = f_y;
        }
    }
};


//union find
class Solution{
public:
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes){
        unordered_set<int> hashset;
        for(UndirectedGraphNode* it : nodes){
            hashset.insert(it->label);
            for(UndirectedGraphNode* neighbor : it->neighbors){
                hashset.insert(neighbor->label);
            }
        }
    }

    UnionFind* uf =  new UnionFind(hashset);

    for(UndirectedGraphNode* it : nodes){
        for(UndirectedGraphNode* neighbor : it->neighbors){
            int fnow = uf->find(it->label);
            int fneighbor = uf->find(neighbor->label);
            if(fnow != fneighbor){
                uf->union(it->label, neighbor->label);
            }
        }
    }

    return dataDump(hashset, uf, nodes.size());
}