#include<iostream>
#include<vector>

using namespace std;

bool findpath(vector<vector<int>>& dungeon, int i, int j, int currenthp, int& minhp)
{
    if (i >= dungeon.size() || j >= dungeon[0].size())
    {
        minhp = - INT_MAX;
        return false;
    }
    currenthp = currenthp + dungeon[i][j];
    if (currenthp < minhp)
        minhp = currenthp;
    if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
    {
        return true;
    }
    int min1 = minhp;
    int min2 = minhp;
    findpath(dungeon, i + 1, j, currenthp, min1);
    findpath(dungeon, i, j + 1, currenthp, min2);
    minhp = min1 > min2 ? min1 : min2;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
    int minhp = 0;
    findpath(dungeon,0,0,0,minhp);
    return  minhp > 0 ? 0 : 1 - minhp;
}
int main()
{
    vector<vector<int>> dungeon = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
    calculateMinimumHP(dungeon);
    return 0;
}