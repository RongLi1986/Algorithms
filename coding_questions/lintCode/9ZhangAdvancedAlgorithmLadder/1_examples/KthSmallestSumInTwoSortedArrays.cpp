/*******************************************************
Description
在两个排序数组中找到第K大元素的和

例子
input:
[4,7,8]
[1,2]
2

return (2+7) = 9

********************************************************/

/*
similar to KthSmallestNumberInSortedMatrix

*/ 

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<int> &a, vector<int> &b, int k) {
        // write your code here
        
        //define priority_queue with custom comparator
        //pair<int, pair<int, int>> ==> (value, (x,y));
        auto comp = [] (pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) -> bool { return a.first > b.first; };
        priority_queue<pair<int, pair<int, int> >,
                vector<pair<int, pair<int, int> >>, 
                decltype(comp) > pq (comp);
        
        //visitor map
        vector<vector<int>> vistor_map(a.size(), vector<int>(b.size(), 0)); 
        
        pq.push({a[0] + b[0], {0, 0}});
        vistor_map[0][0] = 1;
        
        //pop k-1 item
        for(int i = 0; i < k - 1; i++){
            auto item = pq.top();
            pq.pop();
            int x = item.second.first;
            int y = item.second.second;
            //cout<<matrix[x][y]<<endl;
            if(x + 1 >= 0 && x + 1 < a.size() && vistor_map[x + 1][y] == 0){
                pq.push({a[x + 1] + b[y], {x + 1, y}});
                vistor_map[x + 1][y] = 1;
            }

            if(y + 1 >= 0 && y + 1 < b.size() && vistor_map[x][y + 1] == 0){
                pq.push({a[x] + b[y + 1], {x, y + 1}});
                vistor_map[x][y + 1] = 1;
            }
        }
        
        return pq.top().first;
    }
};