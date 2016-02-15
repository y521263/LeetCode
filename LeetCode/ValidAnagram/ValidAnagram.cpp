//https://leetcode.com/problems/valid-anagram/

#include<iostream>

using namespace std;

bool isAnagram(string s, string t) 
{
    const int CHARNUM = 26;
    if (s.size() != t.size()) return false;
    int a[CHARNUM];
    int b[CHARNUM];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < s.size(); i++)
    {
        a[(s[i] - 'a') % CHARNUM]++;
        b[(t[i] - 'a') % CHARNUM]++;
    }
    for (int i = 0; i < CHARNUM; i++)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}
int main()
{
    bool b = isAnagram("anagram", "nagaram");
    return 0;
}