#include<iostream>
#include<vector>

using namespace std;

void ReplaceAll(string& name, string str1, string str2)
{
    std::string::size_type startpos = 0;
    while (startpos != std::string::npos)
    {
        startpos = name.find(str1);
        if (startpos != std::string::npos)
        {
            name.replace(startpos, str1.length(), str2);
        }
    }
}

string addstr(vector<string>::iterator start, vector<string>::iterator end, int numwords, int numspace)
{
    string ret;
    for (auto it = start; it != end; ++it)
    {
        int nspace = 0;
        if (numwords == 1)
            nspace = numspace;
        else
        {
            if (numspace % (numwords - 1))
            {
                nspace = numspace / (numwords - 1) + 1;
                numspace = numspace - 1;
            }
            else
            {
                nspace = numspace / (numwords - 1) ;
                numspace = numspace;
            }
        }
        ret = ret + *it +string( nspace,' ');
    }
    return ret;
}
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    auto start = words.begin();
    auto end = start;
    int len = -1;
    int numwords = 0;
    for (auto it = start; it != words.end(); )
    {
        if (len + it->size() + 1 <= maxWidth || it->size() < 1)
        {
            numwords++;
            len = len + it->size() + 1;
            ++end;
            ++it;
            continue;
        }
        string tt = addstr(start, end, numwords, maxWidth + numwords - len -1);
        tt = tt.substr(0,maxWidth);
        ret.push_back(tt);
        start = end;
        len = -1;
        numwords = 0;
    }
    if (numwords > 0)
    {
        string tt = addstr(start, end, numwords, maxWidth + numwords - len - 1);
        tt = tt.substr(0, maxWidth);
        if (tt.find(".") != string::npos)
        {
            ReplaceAll(tt,"  "," ");
            tt = tt + string(maxWidth - tt.size(),' ');
        }
        ret.push_back(tt);
    }
    return ret;
}
int main()
{
    //vector<string> vec = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> vec = {"Don't", "go", "around", "saying", "the", "world", "owes", "you", "a", "living;", "the", "world", "owes", "you", "nothing;", "it", "was", "here", "first."};
    fullJustify(vec,30);
    return 0;
}