//
//  SubstringwithConcatenationofAllWords.cpp
//  SubstringwithConcatenationofAllWords
//
//  Created by lin on 16/2/25.
//  Copyright © 2016年 lin. All rights reserved.
//
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;
    if (words.size()<1) {
        return result;
    }
    int l = words[0].size();
    int n = words.size();
    int slen = s.size();
    map<string,int> wordmap;
    for (int i= 0; i< words.size(); i++) {
        wordmap[words[i]]++;
    }
    for(int j=0;j<l;j++)
    {
    int count=0;
    int winleft=j;
    map<string,int> currentmap;
    for (int i=j; i<=slen-l ; i=i+l) {
        string wd = s.substr(i,l);
        if (wordmap.find(wd) == wordmap.end()) {
            currentmap.clear();
            count=0;
            winleft = i+l;
            continue;
        }
        count++;
        ++currentmap[wd];
        if(currentmap[wd] > wordmap[wd])
        {
            string tmp;
            do{
                tmp = s.substr(winleft,l);
                currentmap[tmp]--;
                count--;
                winleft+=l;
            }while(tmp != wd);
        }
        
        if (count == n) {
            result.push_back(winleft);
            string tmp = s.substr(winleft,l);
            currentmap[tmp]--;
            count--;
            winleft+=l;
        }
    }
    }
    return result;
}

int main()
{
    //string s = "barfoofoobarthefoobarman";
    //vector<string> words = {"foo", "bar","the"};
    //string s  = "abaababbaba";
    //vector<string> words = {"ab","ba","ab","ba"};
    string s = "mississippi";
    vector<string> words = {"mississippis"};
    findSubstring(s,words);
    return 0;
}