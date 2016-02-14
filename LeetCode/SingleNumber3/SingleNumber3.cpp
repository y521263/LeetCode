//https://leetcode.com/problems/single-number-iii/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    set<int> tmpset;
    for (int i = 0; i < nums.size(); i++)
    {
        if (tmpset.find(nums[i]) != tmpset.end())
            tmpset.erase(nums[i]);
        else
        {
            tmpset.insert(nums[i]);
        }
    }
    vector<int> tmpvec;
    tmpvec.resize(tmpset.size());
    copy(tmpset.begin(),tmpset.end(),tmpvec.begin());
    return tmpvec;
}
int main()
{
    vector<int> tmpvec1 = { 1, 2, 1, 3, 2, 5 };
    auto tmpvec = singleNumber(tmpvec1);
    return 0;
}