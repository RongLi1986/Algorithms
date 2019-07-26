/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Given encoded message 12, it could be decoded as AB (1 2) or L (12).
The number of ways decoding 12 is 2.
*/

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
        
        vector<int> map(s.size(), 0);
        
        map[0] = 1;
        
        if(s.size()==1){
            return map[0];
        }
        
        
        if(s[1]<'1' || s[1]>'9'){   
            if(stoi(s.substr(0,2))<27) 
                map[1] = map[0];
            else  //30
                map[1] = 0;
        }else{
            if(stoi(s.substr(0,2))<27)
                map[1] = map[0] + 1;
            else
                map[1] = map[0];
                
        }
        
        for(int i=2;i<s.size();i++){
            if(stoi(s.substr(i,1))==0){
                if(stoi(s.substr(i-1,2))<27 && stoi(s.substr(i-1,2))>9){
                    map[i] = map[i-2];
                }else{
                    return 0;
                }
            }else{
                if(stoi(s.substr(i-1,2))<27 && stoi(s.substr(i-1,2))>9){
                    map[i] = map[i-1]+map[i-2];
                }else{
                    map[i] = map[i-1];
                }
            }
        }
        
        /*
        for(int i=0;i<s.size();i++){
            cout<<map[i]<<" ";
        }
        cout<<endl;
        */
        
        return map[s.size()-1];
    }
};