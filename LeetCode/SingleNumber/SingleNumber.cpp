#include<iostream>
#include<vector>
#include<map>
using namespace std;


//algo 1
/*
int singleNumber(vector<int>& nums) {
    map<int, int> tmpmap;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        auto tt = tmpmap.find(*it);
        if (tt != tmpmap.end())
        {
            tmpmap.erase(tt);
            continue;
        }
        tmpmap[*it] = *it;
    }
    auto tt = tmpmap.begin();
    return tt->second;
}
*/
//algo 2
int singleNumber(vector<int>& nums) {
    int s = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        s = s ^ *it;
    }
    return s;
}
int main()
{
    return 0;
}