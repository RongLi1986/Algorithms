/*
132 word search II

Given a matrix of lower alphabets and a dictionary. 
Find all words in the dictionary that can be found in the matrix. 
A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 
One character only be used once in one word. No same word in dictionary.

Example 1:

Input：["doaf","agai","dcan"]，["dog","dad","dgdg","can","again"]
Output：["again","can","dad","dog"]
Explanation：
  d o a f
  a g a i
  d c a n
search in Matrix，so return ["again","can","dad","dog"].
*/

struct Node {    				//定义字典树的节点
    vector<Node*> ch(26, NULL);				//因为有26个英文字母，开26个长度
    string str = "";
    Node() {
        // for (int i = 0; i < 26; ++i)   
        //     ch[i] = NULL;
        //     str = "";
    }
};

class Solution {
public:
    vector<string> results;
    Node* root;

    void insert(Node* p, string s) {			//字典树插入单词
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (p->ch[s[i]-'a'] == NULL)		//如果当前节点为空
                p->ch[s[i]-'a'] = new Node();	//新建节点
            p = p->ch[s[i]-'a'];                //继续遍历
        }   
        p->str = s;								//最后一个节点保存字符串
    }
    
    void search(vector<vector<char> > &board, vector<vector<bool> > &mask, Node* p, int x, int y) {  //在字典树上dfs查找
        if (p->str != "") {				//如果访问到字典树叶子，将字符串压入result即可
            results.push_back(p->str);
            p->str = "";
        }

        mask[x][y] = false;			//标记mask[x][y]，避免重复访问
        if (y + 1 < board[0].size() && mask[x][y+1] && p->ch[board[x][y+1]-'a'] != NULL) {  //访问[x][y+1]
           search(board,mask, p->ch[board[x][y+1]-'a'], x, y+1);
        }

        if (x + 1 < board.size() && mask[x+1][y] && p->ch[board[x+1][y]-'a'] != NULL) {	//访问[x+1][y]
           search(board,mask, p->ch[board[x+1][y]-'a'], x+1, y);
        }

        if (y - 1 >= 0 && mask[x][y-1] && p->ch[board[x][y-1]-'a'] != NULL) {		//访问[x][y-1]
           search(board,mask, p->ch[board[x][y-1]-'a'], x, y-1);
        }

        if (x - 1 >= 0 && mask[x-1][y] && p->ch[board[x-1][y]-'a'] != NULL) {	//访问[x-1][y]
           search(board,mask, p->ch[board[x-1][y]-'a'], x-1, y);
        }
        mask[x][y] = true;				//搜索后mask[x][y]可以访问
    }

    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        root = new Node();
        int len = words.size();

        //插入单词构造字典树
        for (int i = 0; i < len; ++i) {
            insert(root, words[i]);
        }

        vector<vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));

        if (board.size() < 1) return results;
        
        //遍历字母矩阵，将每个字母作为单词首字母开始搜索
        for (int i = 0; i <board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
               if (root->ch[board[i][j]-'a'] != NULL) {
                    search(board, mask, root->ch[board[i][j]-'a'], i, j);  //开始dfs搜索
                 }
            }
        }
        
        return results;
    }
};