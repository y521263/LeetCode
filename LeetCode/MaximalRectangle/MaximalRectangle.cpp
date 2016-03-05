//
//  MaximalRectangle.cpp
//  MaximalRectangle
//
//  Created by lin on 16/2/26.
//  Copyright © 2016年 lin. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.size()<1) return 0;
    int row =matrix.size();
    int col = matrix[0].size();
    int arr[row][col];
    memset(arr, 0, sizeof(arr));
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            if(matrix[i][j] == '0') continue;
            
            int up = i-1<0 ? 0: arr[i-1][j];
            int left = j-1<0 ? 0 :arr[i][j-1];
            int tmp = min(up, left);
            if(matrix[i-tmp][j-tmp] == '1')
                arr[i][j] = tmp+1;
            else
                arr[i][j]= max(tmp,1);
            
        }
    }
    int result=0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if(arr[i][j]>result)
            {
                result = arr[i][j];
            }
        }
    }
    return result;
}

int main()
{
    
    return 0;
}