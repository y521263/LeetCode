//https://leetcode.com/problems/wildcard-matching/

#include<iostream>
#include<string>

using namespace std;
bool isMatch(string s, string p) {
    auto its = s.begin();
    auto itp = p.begin();
    auto last_s = s.end();
    auto last_p = p.end();
    while (its != s.end() )
    {
        if (itp != p.end() && *itp == '*')
        {
            itp++;
            if (itp == p.end()) return true;
            //出现 * 作下标记
            last_s = its;
            last_p = itp;
        }
        else if (itp != p.end() &&  (*itp == '?' || *its == *itp) )
        {
            its++;
            itp++;
        }
        else if (last_p != p.end())//匹配不上 并且 前面出现了 * 那么重置 p指针的位置
        {
            itp = last_p;
            its = ++last_s;//这里的 ++  表示 放入 * 匹配的内容中。
        }
        else
            return false;
    }
    //s 指针结束了 p 还没结束
    while (itp != p.end() && *itp == '*')
        itp++;
    return itp == p.end();
}

int main()
{
    cout << isMatch("hi", "*?") << endl;
    cout << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
    cout << isMatch("aa", "aa") << endl;
    cout << isMatch("aaa", "aa") << endl;
    cout << isMatch("aa", "*") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    return 0;
}