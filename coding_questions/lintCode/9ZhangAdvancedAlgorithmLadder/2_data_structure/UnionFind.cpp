/*******************************************************
UnionFind implment code
********************************************************/


/*
find: O(N)
union: O(N)

compression path
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