//
//  ContainsDuplicate.cpp
//  ContainsDuplicate
//
//  Created by lin on 16/2/25.
//  Copyright © 2016年 lin. All rights reserved.
//
//https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
/*
bool containsDuplicate(vector<int>& nums) {
    set<int> settmp;
    for(int i= 0;i<nums.size();i++)
    {
        if(settmp.find(nums[i]) != settmp.end()) return true;
        settmp.insert(nums[i]);
        
    }
    return false;
}*/
bool containsDuplicate(vector<int>& nums)
{
    unordered_set<int> settmp;
    for(int i= 0;i<nums.size();i++)
    {
        if(settmp.find(nums[i]) != settmp.end()) return true;
        settmp.insert(nums[i]);
        
    }
    return false;
}
int main()
{
    return 0;
}