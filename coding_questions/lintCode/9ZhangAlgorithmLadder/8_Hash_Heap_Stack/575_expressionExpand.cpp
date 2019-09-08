/*
Expression Expand

Given an expression s includes numbers, letters and brackets. Number represents 
the number of repetitions inside the brackets(can be a string or another expression)．Please expand expression to be a string.

Example
s = abc3[a] return abcaaa
s = 3[abc] return abcabcabc
s = 4[ac]dy, return acacacacdy
s = 3[2[ad]3[pf]]xyz, return adadpfpfpfadadpfpfpfadadpfpfpfxyz
*/


/*
*/

class Solution {
private:
    unordered_map<int,int> hashmap; ///index of [ and ]
    stack<int> st1;
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
        // Write your code here
        preprocessing(s);
        return helper(s,0,s.size(), 1);
    }
    
    //o(n)
    void preprocessing(string& s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st1.push(i);
            }   
            
            if(s[i]==']'){
                int start = st1.top();
                st1.pop();
                
                hashmap[start] = i;
            }
        }    
        
        return;
    }
    
    //O(n)
    string helper(string s, int begin, int stop,  int num){
        string tmp;
        string res;
        if(s.size()==0) return res;
        
        int i = begin;
        while(i < stop){
            if(isdigit(s[i])){
                string numStr;
                
                while(isdigit(s[i])){
                    numStr+=s[i];
                    i++;
                }
                
                int start = i; //index of [
                int end = hashmap[start];
                
                //cout<<start<<" "<<end<<endl;
                tmp+=helper(s, start+1, end ,stoi(numStr));
                i=end;
                
            }else{
                tmp+=s[i];
            }
            
            i++;
        }
        
        for(int i = 0;i<num;i++){
            res +=tmp;
        }
        
        return res;
    }

};