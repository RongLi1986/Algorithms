/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Given word1 = "mart" and word2 = "karma", return 3.
*/

#include <iostream>
using namespace std;

/*

*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        if(word2.empty())
            return word1.size();
        
        if(word1.empty())
            return word2.size();
        
        vector<vector<int > > map(word2.size(), vector<int>(word1.size(), 0));
        
        int flag1=0;
        int flag2=0;
        if(word1[0]==word2[0]){
            map[0][0] = 0;
            flag1 = 1;
            flag2 = 1;
        }else
            map[0][0] = 1;
        
        
        //initial first col
        for(int i=1;i<word2.size();i++){
            if(word2[i]==word1[0] && flag1==0){
                map[i][0]=map[i-1][0];
                flag1=1;
            }else{
                map[i][0]=map[i-1][0]+1;
            }
        }
        
        
        //initial first row
        for(int i=1;i<word1.size();i++){
            if(word2[0]==word1[i] && flag2==0){
                map[0][i]=map[0][i-1];
                flag2=1;
                
            }else{
                map[0][i]=map[0][i-1]+1;
                
            }
        }
        
        for(int i=1;i<word2.size();i++){
            for(int j=1;j<word1.size();j++){
                if(word2[i]==word1[j]){
                    map[i][j]=min(map[i-1][j-1], min(map[i-1][j]+1,map[i][j-1]+1));;
                }else{
                    map[i][j]=min(map[i-1][j-1]+1, min(map[i-1][j]+1,map[i][j-1]+1));
                }
            }
        }
        
        /*
        for(int i=1;i<word2.size();i++){
            for(int j=1;j<word1.size();j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        
        return map[word2.size()-1][word1.size()-1];
    }
};




int main(){

	return 0;
}