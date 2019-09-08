/*
strStr II

Implement strStr function in O(n + m) time.

strStr return the first index of the target string in a source string. The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.

Have you met this question in a real interview? Yes
Example
Given source = abcdef, target = bcd, return 1.


*/

#include <iostream>
using namespace std;

/*
KMP O(n + m)
*/

class Solution {
public:
    /**
     * @param source a source string
     * @param target a target string
     * @return an integer as index
     */
    vector<int> KMPpreprocessing(const char *s) {
        int n = strlen(s);
        vector<int> match(n,-1);
        int j = -1;
        for(int i=1; i<n; i++) {
            while(j>=0 && s[i]!=s[j+1]) j = match[j];
            if(s[i]==s[j+1]) j++;
            match[i] = j;
        }
        return match;
    }


    int strStr2(const char *haystack, const char *needle) {
        if(needle==NULL) return -1;
        if(haystack==NULL) return -1;
        int m = strlen(haystack), n = strlen(needle);
        if(m==0&&n==0) return 0;
        if(m==0) return -1;
        if(n==0) return 0;
        vector<int> match = KMPpreprocessing(needle);
        int j = -1;
        for(int i=0; i<m; i++) {
            while(j>=0 && haystack[i]!=needle[j+1]) j = match[j];
            if(haystack[i]==needle[j+1]) j++;
            if(j==n-1) return (i-n+1);
        }
        return -1;
        
    }
};

//Test
int main(){

	return 0;
}