//https://leetcode.com/problems/move-zeroes/

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < nums.size()-num;)
    {
        if (nums[i])
        {
            i++;
            continue;
        }
        else
        {
            num++;
            nums.push_back(0);
            nums.erase(nums.begin() + i);
        }
    }
}
int main()
{
    vector<int> nums = { 0, 1, 0, 3, 12 };
    moveZeroes(nums);
    return 0;
}