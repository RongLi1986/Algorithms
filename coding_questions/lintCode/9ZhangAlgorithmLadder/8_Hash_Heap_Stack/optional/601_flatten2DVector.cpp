/*
Flatten 2D Vector

Implement an iterator to flatten a 2d vector.

Have you met this question in a real interview? Yes
Example
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1,2,3,4,5,6].
*/
 
class Vector2D {
private:
    vector<int> vec;
    int ptr;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        ptr=0;
        for(int i = 0;i<vec2d.size();i++){
            for(int j=0;j<vec2d[i].size();j++){
                vec.push_back(vec2d[i][j]);
            }
        }
    }

    int next() {
        // Write your code here
        int ans =vec[ptr];
        ptr++;
        return ans;
    }

    bool hasNext() {
        // Write your code here
        return ptr<vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */