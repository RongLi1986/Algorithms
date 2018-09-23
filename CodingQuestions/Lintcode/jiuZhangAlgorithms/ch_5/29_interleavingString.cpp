/*
Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.

Example
For s1 = "aabcc", s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.empty()){
            if(s2.size()==s3.size())
                return true;
        }
        
        if(s2.empty()){
            if(s1.size()==s3.size())
                return true;
        }
        
        if( s1.size() + s2.size() != s3.size() )
            return false;
        
        vector<vector<int> > map(s2.size(), vector<int>(s1.size(),0));
        
        
        if((s1[0]==s3[0]) || (s1[0]==s3[1])){
            map[0][0] =1;
        }
        
        for(int i=1;i<map.size();i++){
            if((s2[i]==s3[i]  || s1[0] == s3[i] || s2[i] == s3[i+1] ) && map[i-1][0]== 1)
                map[i][0] =1;
        }
        
        for(int i=1;i<map[0].size();i++){
            if((s1[i]==s3[i] || s2[0]== s3[i] || s1[i] == s3[i+1]) && map[0][i-1] == 1)
                map[0][i] =1;
        }
        
        for(int i=1;i<map.size();i++){
            for(int j=1;j<map[0].size();j++){
                if((s2[i]==s3[i+1+j] && map[i-1][j]==1) || (s1[j]==s3[i+1+j] && map[i][j-1]==1) )
                    map[i][j]=1;
            }
        }
        
        /*
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                cout<< map[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        
        return map[s2.size()-1][s1.size()-1];
    }
};