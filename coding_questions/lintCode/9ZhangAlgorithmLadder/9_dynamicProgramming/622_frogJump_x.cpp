/*
Frog Jump

A frog is crossing a river. The river is divided into x units and at each unit 
there may or may not exist a stone. The frog can jump on a stone, but it must 
not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine 
if the frog is able to cross the river by landing on the last stone. Initially, 
the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, 
or k + 1 units. Note that the frog can only jump in the forward direction.

Notice

The number of stones is ≥ 2 and is < 1100.
Each stone's position will be a non-negative integer < 2^31.
The first stone's position is always 0.
*/

//http://www.cnblogs.com/grandyang/p/5888439.html
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        return helper(stones, 0, 0, m);
    }
    bool helper(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m) {
        int n = stones.size(), key = pos | jump << 11;
        if (pos >= n - 1) return true;
        if (m.count(key)) return m[key];
        for (int i = pos + 1; i < n; ++i) {
            int dist = stones[i] - stones[pos];
            if (dist < jump - 1) continue;
            if (dist > jump + 1) return m[key] = false;
            if (helper(stones, i, dist, m)) return m[key] = true;
        }
        return m[key] = false;
    }
};