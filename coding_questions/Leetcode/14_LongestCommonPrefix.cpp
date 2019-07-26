/*
Longest Common Prefix 
Write a function to find the longest common prefix string amongst an array of strings.
*/
#include <iostream>
#include <vector>

using namespace std;

/*
set a prefix equal to first string, then travese vector,
for each comparsion, find new prefix and update it.
if prefix is NULL, return
*/


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string prefix;

    	if(strs.size()==0)  //vector is empty
    		return prefix;

    	prefix.append(strs[0]); //set first string

    	for(int i=1;i<strs.size();i++){
            if(prefix.empty()) return prefix;
    		int j=0;
    		while(j<prefix.size()&&j<strs[i].size()){
    			if(prefix[j]!=strs[i][j])
    				break;
    			j++;
    		}
    		prefix.clear();
    		prefix.append(strs[i],0,j);  //update new string
    	}

    	return prefix;
    }
};

int main(){
	string a="abc";
	string b="ab";
	string c="ab";

	vector<string> strs;
	//strs.push_back(a);
	strs.push_back(b);
	//strs.push_back(c);


	Solution s;
	cout<<s.longestCommonPrefix(strs)<<endl;


	return 0;
}