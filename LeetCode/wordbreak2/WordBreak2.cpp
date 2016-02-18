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

       0  c  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
             "cats" -- word[0,3] + {result[4]}  ==> "cats and dog"
       1  a  ""
       2  t  ""
       3  s  "sand" --  word[3,6] + {result[7]} ==> "sand dog"
       4  a  "and"  --  word[4,6] + {result[7]} ==> "and dog"
       5  n  ""
       6  d  ""
       7  d  "dog"
       8  o  ""
       9  g  ""
*/

//Result: Time Limit Exceeded
/*
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector< vector<string> > result(s.size());
    for (int i = s.size() - 1; i >= 0; i--)
    {
        vector<string> v;
        result[i] = v;
        for (int j = i + 1; j <= s.size(); j++)
        {
            string wd = s.substr(i, j - i);
            if (wordDict.find(wd) != wordDict.end())
            {
                if (j == s.size())
                    result[i].push_back(wd);
                else
                {
                    for (int k = 0; k < result[j].size(); k++)
                    {
                        result[i].push_back(wd + " " + result[j][k]);
                    }
                }
            }
        }
    }
    return result[0];
}*/
/*Result: Time Limit Exceeded
void dfs(string& s, vector<string>& ret, string tmp, int pos, vector< vector<int> >& rec)
{
    if (pos < 1)
    {
        ret.push_back(tmp);
        return;
    }
    for (int i = 0; i < rec[pos].size(); i++)
    {
        dfs(s, ret, s.substr(rec[pos][i], pos - rec[pos][i]) + " " + tmp, rec[pos][i], rec);
    }
}

//先用 dp 找到所有 可切分的 位置，再用dfs 查找所有可能的情况
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> result;
    vector< vector<int> > rec(s.size());
    vector<bool> f(s.size(), false);
    f[0] = true;
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (f[j] && (wordDict.find(s.substr(j, i - j)) != wordDict.end()))
            {
                rec[i].push_back(j);
                f[i] = true;
            }
        }
    }
    for (int i = s.size()-1; i>=0; i--)
    {
        if (rec[i].size() > 0)
        {
            dfs(s, result, s.substr(i,s.size()-i), i, rec);
            break;
        }
    }
    return result;
}
*/
void dfs(const string&s, vector<string>& ans, string str, int dep, const vector<vector<int> >& rec) {
    if (dep <= 0) {
        ans.push_back(str.substr(0, str.size() - 1));
        return;
    }
    for (int i = 0; i < rec[dep].size(); i++) {
        dfs(s, ans, s.substr(rec[dep][i] + 1, dep - rec[dep][i]) + " " + str, rec[dep][i], rec);
    }
}
//先用 dp 找到所有 可切分的 位置，再用dfs 查找所有可能的情况
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> ans;
    s = "#" + s;
    vector<vector<int> > rec(s.size());
    vector<bool> f(s.size(), false);
    f[0] = true;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (f[j] && dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                rec[i].push_back(j);
                f[i] = true;
            }
        }
    }
    dfs(s, ans, "", s.size() - 1, rec);
    return ans;
}

int main()
{
    string s = "catsanddog";
    unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
    wordBreak(s, wordDict);
    return 0;
}