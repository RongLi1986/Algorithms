/*
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.
 
Example
Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".
*/

#include <iostream>
using namespace std;

/*
DP solution:
f(i) is it could be cut at string (i-1) 

f(0) =1;

for i:
if(f(j)==1) && (string[j:i] in dict) 
    f(i) =1 

return f(string.size())
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        vector<int> cutMap(s.size()+1, 0);
        
        cutMap[0] = 1;
        
        for(int i = 1; i<cutMap.size();i++){
            for(int j = i;j > 0;j--){
                //corner case large set
                //for normal word, size should small than 10;
                if (i-j>10)
                    break;
                
                //cout<<s.substr(j-1, i-j+1)<<endl;
                if(cutMap[j-1]==1 && dict.find(s.substr(j-1, i-j+1))!=dict.end()){
                    //cout<<"set "<<i<<endl;
                    cutMap[i] =1;
                    break;
                }
            }
            //cout<<endl;
        }
        
        /*
        for(int i=0;i<cutMap.size();i++){
            cout<<cutMap[i]<<" ";
        }
        cout<<endl;
        */
        
        return cutMap[cutMap.size()-1]==1;
    }
};

int main(){

	return 0;
}