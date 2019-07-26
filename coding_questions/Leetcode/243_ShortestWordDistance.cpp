/*
243. Shortest Word Distance   
Given a list of words and two words word1 and word2, return the 
shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int minDis = INT_MAX;
        int index1 = -1;  //keep last word1 loc
        int index2 = -1;  //keep last word2 loc
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){  //find word1, caculate to word2
                if(index2!=-1){
                    minDis = min(minDis,i-index2);
                }
                index1 = i;
            }
            
            if(words[i]==word2){  //find word2, caculate to word1
                if(index1!=-1){
                    minDis = min(minDis,i-index1);
                }
                index2 = i;
            }
            
        }
        
        return minDis;
    }
    
    int shortestDistance_bruteForce(vector<string>& words, string word1, string word2) {
        int minDis = INT_MAX;
        //int flag = 0;
        
        vector<int> wordsLoc1;
        vector<int> wordsLoc2;
        
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){
                wordsLoc1.push_back(i);
            }
            
            if(words[i]==word2){
                wordsLoc2.push_back(i);
            }
        }
        
        for(int i=0;i<wordsLoc1.size();i++){
            for(int j=0;j<wordsLoc2.size();j++){
                if(minDis > abs(wordsLoc1[i]-wordsLoc2[j])){
                    minDis = abs(wordsLoc1[i]-wordsLoc2[j]);
                }
            }
        }
        
        
        return minDis;
    }
};