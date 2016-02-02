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
            //���� * ���±��
            last_s = its;
            last_p = itp;
        }
        else if (itp != p.end() &&  (*itp == '?' || *its == *itp) )
        {
            its++;
            itp++;
        }
        else if (last_p != p.end())//ƥ�䲻�� ���� ǰ������� * ��ô���� pָ���λ��
        {
            itp = last_p;
            its = ++last_s;//����� ++  ��ʾ ���� * ƥ��������С�
        }
        else
            return false;
    }
    //s ָ������� p ��û����
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