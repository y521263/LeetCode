//https://leetcode.com/problems/word-break-ii/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
//Result: Time Limit Exceeded
/*
void findword(int start, int pos, string& s, unordered_set<string>& wordDict,string ret, vector<string>& result)
{
    if (pos > s.size()) return;
    while (pos <= s.size() && wordDict.find(s.substr(start, pos - start)) == wordDict.end())
        pos++;
    if (wordDict.find(s.substr(start, pos - start)) == wordDict.end()) return;

    findword(start, pos + 1, s, wordDict, ret, result);
    ret = ret + s.substr(start, pos - start);
    if (pos < s.size())
        ret += " ";
    else
    {
        result.push_back(ret);
        return;
    }
    start = pos;
    findword(start, start + 1, s, wordDict, ret, result);
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int pos = 0;
    int start = 0;
    vector<string> result;
    findword(start, pos, s, wordDict, "", result);
    return result;
}
*/
/*
动态规划法
s[i,j]表示s串[i,j]区间的字符串 : result[i] = s[i,j] + {result[j]} 这里的 {result[j]} 是个vector  有好多个 字符串

s = "catsanddog"
dict = ["cat", "cats", "and", "sand", "dog"].
倒过来看

*/
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector< vector<string> > result;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            string wd = s.substr(i, j - i);
            if (wordDict.find(wd) != wordDict.end())
            {
                if ()
                result[i].push_back(wd);
            }
        }
    }
}

int main()
{
    string s = "catsanddog";
    unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
    //wordBreak(s, wordDict);
    return 0;
}