//https://leetcode.com/problems/dungeon-game/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 
// time limited
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
}*/
int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    const int row = dungeon.size();
    const int col = row > 0 ? dungeon[0].size() : 0;
    int dp[row][col];
    memset(dp, 0, sizeof(dp));
    for (int r = row - 1; r >= 0; r--)
    {
        for (int c = col - 1; c >= 0; c--)
        {
            if (c == col - 1 && r == row - 1)
            {
                dp[r][c] = max(1 - dungeon[r][c], 1);
            }
            else
            {
                int rr = (r >= row - 1) ? INT_MAX : max(dp[r + 1][c] - dungeon[r][c], 1);
                int cc = (c >= col - 1) ? INT_MAX : max(dp[r][c + 1] - dungeon[r][c], 1);
                dp[r][c] = min(rr, cc);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    //vector<vector<int>> dungeon = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
    vector<vector<int>> dungeon = { { 0 } };
    calculateMinimumHP(dungeon);
    return 0;
}