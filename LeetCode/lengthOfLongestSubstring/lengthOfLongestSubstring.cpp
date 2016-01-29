#include<iostream>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int m[256];
	memset(m, -1, sizeof(m));
	int num = -1;
	int maxlen = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] != -1 &&  num < m[s[i]] )
		{
			num = m[s[i]];
		}
		if (i - num > maxlen)
		{
			maxlen = i - num;
		}
		m[s[i]] = i;
	}
	return maxlen;
}
int main()
{
	//abcabcbb
	//lengthOfLongestSubstring("au");
	//lengthOfLongestSubstring("abcabcbb");
	lengthOfLongestSubstring("a");
	return 0;
}