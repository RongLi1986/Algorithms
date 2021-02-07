# 1711. Count Good Meals

## Question link
(https://leetcode.com/problems/count-good-meals/)

## Question Description

A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.

 
Example 1:

Input: deliciousness = [1,3,5,7,9]
Output: 4
Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.

Example 2:

Input: deliciousness = [1,1,1,3,3,3,7]
Output: 15
Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.
 

Constraints:

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220

##
hashtable, two sum

```c++
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        //count numbers
        map<int, int> m;
        for(int i = 0; i < deliciousness.size(); i++){
            m[deliciousness[i]]++;
        }
        
        // 2 pow 20 list
        vector<int> s = {1};
        int t = 1;
        for(int i = 0; i < 21; i++){
            t *= 2;
            s.push_back(t);
        }
        
        // find pairs
        long long ans = 0;
        for(auto itr = m.begin(); itr != m.end(); itr++){
            int k = itr->first;
            for(int i = 0; i < s.size(); i++){
                int t = s[i] - k;
                if(m.find(t) != m.end() && t >= k){
                    // cout<<k << " "<<t<<endl;
                    if(t == k){
                        if(m[t] == 1) continue;
                        ans += (long)m[t] * (long)(m[t] - 1) / 2;
                    }else{
                        ans += (long)m[t] * (long)itr->second;
                    }
                    ans %= 1000000007;
                    // cout<<ans<<endl;
                }
            }
        }
        
        return ans;
    }
};
```