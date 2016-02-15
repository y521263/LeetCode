//https://leetcode.com/problems/word-search-ii/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int MAX_CHARS = 26;
class TrieNode
{
public:
    TrieNode(string s) :isWord(false), word(s){
        memset(children,0,sizeof(children));
    }
    TrieNode* & operator [] (char ch){
        return children[(ch - 'a')%MAX_CHARS];
    }
    TrieNode* & operator [] (int inx){
        return children[inx%MAX_CHARS];
    }
public:
    string word;
    bool isWord;
private:
    TrieNode* children[MAX_CHARS];
};

class TrieTree
{
public:
    TrieTree():root(new TrieNode("")){}
    TrieNode* getroot()
    {
        return root;
    }
    void addword(string s)
    {
        TrieNode* node = root;
        string t;
        for (int i = 0; i < s.size(); i++)
        {
            t += s[i];
            if ((*node)[s[i]] == NULL)
            {
                (*node)[s[i]] = new TrieNode(t);
            }
            node = (*node)[s[i]];
        }
        node->isWord = true;
    }
    void freeTree(TrieNode* node)
    {
        for (int i = 0; i < MAX_CHARS; i++)
        {
            freeTree((*node)[i]);
        }
        delete node;
    }
private:
    TrieNode* root;
};
void findWords2(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result) {
    if (row<0 || col<0 || row>=board.size() || col >= board[row].size() || board[row][col] == '\0')
        return;

    char ch = board[row][col];
    root = (*root)[ch];
    if (root == NULL)
    {
        return;
    }
    if (root->isWord)
    {
        result.push_back(root->word);
        root->isWord = false;
        //没有 return 可能后面还有word
    }
    //if (prefixstrset.find(root->word) == prefixstrset.end()) return;
    board[row][col] = '\0';
    findWords2(board, root, row, col - 1, result);
    findWords2(board, root, row, col + 1, result);
    findWords2(board, root, row - 1, col, result);
    findWords2(board, root, row + 1, col, result);
    board[row][col] = ch;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieTree root;
    set<string> prefixstrset;
    set<char> tmpset;
    for (int i = 0; i < words.size(); i++)
    {
        root.addword(words[i]);
        tmpset.insert(words[i][0]);
        /*for (int j = 0; j < words[i].size(); j++)
        {
            prefixstrset.insert(words[i].substr(0, j));
        }*/
    }

    vector<string> result;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            //过滤不是word开头的查找 小优化
            if (tmpset.find(board[i][j]) == tmpset.end()) continue;
            findWords2(board, root.getroot(),i, j, result);
            //findWords2(board, root.getroot(),i, j, result,prefixstrset);
        }
    }
    return result;
}
int main()
{
    vector<vector<char>> board;
    board.push_back({ 'o', 'a', 'a', 'n' });
    board.push_back({ 'e', 't', 'a', 'e' });
    board.push_back({ 'i', 'h', 'k', 'r' });
    board.push_back({ 'i', 'f', 'l', 'v' });
    vector<string> words = { "oath", "pea", "eat", "rain" };
    vector<string> ret = findWords(board, words);
    return 0;
}