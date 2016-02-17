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

*/
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

}

int main()
{
    string s = "catsanddog";
    unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
    //wordBreak(s, wordDict);
    return 0;
}