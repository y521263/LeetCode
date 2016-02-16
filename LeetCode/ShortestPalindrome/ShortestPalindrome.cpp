//https://leetcode.com/problems/shortest-palindrome/
#include<iostream>
#include<vector>

using namespace std;

vector<int> KMP(string s){
    vector<int> next(s.size());
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j >0 && s[i]!= s[j])
        {
            j = next[j - 1];
        }
        if (s[i] == s[j])
        {
            ++j;
        }
        next[i] = j;
    }
    return next;
}
//����KMP�㷨 �ҵ����һ���ַ����Ĳ���ƥ���� ���ٽ�ԭ�����ַ������ȼ�ȥ����
string shortestPalindrome(string s) {
    string pat = s +'#'+ string(s.rbegin(), s.rend());
    auto kmpvec = KMP(pat);
    int pos =s.size() - kmpvec.back();
    return string(s.rbegin(),s.rbegin()+pos)+s;
}
int main()
{
    //vector<int> vec = KMP("abcd");
    string s = shortestPalindrome("aacecaaa");
    return 0;
}