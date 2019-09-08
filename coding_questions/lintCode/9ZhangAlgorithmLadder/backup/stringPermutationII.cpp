/*
Given a string, find all permutations of it without duplicates.

Have you met this question in a real interview? Yes
Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].
*/

/*
same as permutation II ( use sort for avoiding duplicates)
*/

class Solution {
private:
    vector<string> res;
public:
    /**
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) {
        // Write your code here

        //unordered_map<string, int> visitedMap; //index, bool
        vector<int> indexMap(str.size(),0);
        //res.push_back(str);
        string tgt;
        
        sort(str.begin(), str.end());
        
        stringPermutation2Helper(str, tgt, indexMap);
        
        return res;
    }
    
    void stringPermutation2Helper(string& str, string& tgt, vector<int>& indexMap){
        if(tgt.size()==str.size()){
            res.push_back(tgt);
            return;
        }
        
        for(int i=0;i<str.size();i++){
            if(i>0 && (str[i] == str[i-1]) && (indexMap[i-1] == 0) )
                continue;
            
            if(indexMap[i]==0){
                indexMap[i] = 1;
                //tgt.push_back(str[i]);
                string tmp = tgt + str[i];
                stringPermutation2Helper(str, tmp, indexMap);
                //tgt.pop_back();
                indexMap[i] = 0;
            }
        }
        
        return;
    }
    
};