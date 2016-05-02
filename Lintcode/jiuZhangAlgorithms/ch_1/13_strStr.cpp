/*
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
*/

#include <iostream>
using namespace std;

/*
O(n^2) ways
TODO: try to use kmp algorithms
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // passed NULL ptr case
        if (source == NULL || target == NULL)
            return -1;

        // get length
        int sourceLen = strlen(source);
        int targetLen = strlen(target);

        //target is empty case
        if (targetLen == 0)
            return 0;

        for (int i = 0; i < sourceLen - targetLen + 1; i++) {
            int tmp_i = i;
            for (int j = 0; j < targetLen; j++) {
                if ( source[tmp_i] == target[j] ) {
                    if ( j == targetLen-1 )
                        return i;
                    tmp_i++;
                } else {
                    break;
                }
            }
        }

        return -1;
    }
};

//Test
int main(){
    Solution s;
    cout<< s.strStr(NULL, NULL) <<endl;
    cout<< s.strStr("","") <<endl;
    cout<< s.strStr("abc","abcd") <<endl;
    cout<< s.strStr("abcde", "cd") <<endl;

	return 0;
}