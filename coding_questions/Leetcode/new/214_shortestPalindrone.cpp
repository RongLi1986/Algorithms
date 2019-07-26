/*
214. Shortest Palindrome My Submissions QuestionEditorial Solution
Total Accepted: 18012 Total Submissions: 92572 Difficulty: Hard
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

Subscribe to see which companies asked this question
*/


//normal solution: c++ cannot pass large data set
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        int postfix=-1;
        for(int i=s.size()-1;i>=0;i--){
            string tmp=s.substr(0,i+1);
            //cout<<tmp<<endl;
            if(isPalindrome(tmp)){
                postfix=i;
                break;
            }
        }
        //cout<<postfix<<endl;
        
        if (postfix == s.size()-1) { 
            return s; 
        }
        
        string rev_s = s.substr(postfix+1,s.size()-postfix-1);
        reverse(rev_s.begin(), rev_s.end());
        
        return rev_s+s;
    }
    
    //O(n^2) 
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        
        while(start<end){
           //cout<<s[start]<<" "<<end<<endl;
            if(!isalnum(s[start])){
                start++;
            }else if(!isalnum(s[end])){
                end--;
            }else{
                s[start] = toupper(s[start]);
                s[end] = toupper(s[end]);
                if(s[start]!=s[end])
                    return false;
                start++;
                end--;
            }
        }
        
        return true;
        
    }
};


//solution: use Manacher find longest palindrone string O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        vector<vector<bool> > map(s.size(),vector<bool>(s.size(),0));
        getIsPalindrome(s, map);
        
        if(s.empty()) return s;
        int postfix=-1;
        for(int i=s.size()-1;i>=0;i--){
            
            //cout<<"kk"<<endl;
            if(map[0][i]){
                //cout<<s.size()<<endl;
                postfix=i;
                break;
            }
        }
        //cout<<postfix<<endl;
        
        if (postfix == s.size()-1) { 
            return s; 
        }
        
        string rev_s = s.substr(postfix+1,s.size()-postfix-1);
        reverse(rev_s.begin(), rev_s.end());
        
        return rev_s+s;
    }

    //O(n) ????
    void getIsPalindrome(string &s, vector<vector<bool> > &map) {
        for (int i = 0; i < s.size(); i++) {
            map[i][i] = true;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            map[i][i + 1] = (s[i] == s[i + 1]);
        }

        for (int length = 2; length < s.size(); length++) {
            for (int start = 0; start + length < s.size(); start++) {
                map[start][start + length] = map[start + 1][start + length - 1] && s[start] == s[start + length];
            }
        }

        return;
    }
    
};

int main(){

    return 0;
}