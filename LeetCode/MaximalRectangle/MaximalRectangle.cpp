//
//  MaximalRectangle.cpp
//  MaximalRectangle
//
//  Created by lin on 16/2/26.
//  Copyright © 2016年 lin. All rights reserved.
//

//https://leetcode.com/problems/maximal-rectangle/

#include <stdio.h>
#include <vector>
using namespace std;

/*
int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.size()<1) return 0;
    int row =matrix.size();
    int col = matrix[0].size();
    int arr[row][col];
    memset(arr, 0, sizeof(arr));
    int rowmax=0;
    int tmpmax = 0;
    for (int i=0;i<row;i++)
    {
        rowmax=0;
        for (int j=0;j<col;j++)
        {
            if(matrix[i][j] == '0')
            {
                rowmax=0;
                continue;
            }
            rowmax++;
            if (rowmax>tmpmax) {
                tmpmax = rowmax;
            }
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
    int colmax=0;
    for (int i=0; i<col; i++) {
        colmax=0;
        for (int j=0; j<row; j++) {
            if (matrix[j][i] != '0') {
                colmax++;
                if (colmax>tmpmax) {
                    tmpmax = colmax;
                }
            }
            if(arr[j][i]>result)
            {
                result = arr[j][i];
            }
        }
    }
    return max(result,tmpmax);
}
*/
//http://www.cnblogs.com/felixfang/p/3676193.html
int largestRectangleArea(vector<int> &height) {
    
    if (height.size()<=0) return 0;
    
    height.push_back(0);
    vector<int> stack;
    int maxArea=0;
    
    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    
    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));
    int maxArea=0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if(matrix[i][j] == '1')
            {
                heights[i][j] = (i==0 ? 1 : heights[i-1][j]+1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if(area>maxArea)
        {
            maxArea = area;
        }
    }
    return maxArea;
}
int main()
{
    vector<vector<char>>  vec;
    vec.push_back({'1','1','1','0','1','1'});
    vec.push_back({'1','0','1','0','1','1'});
    vec.push_back({'1','1','1','0','1','1'});
    vec.push_back({'0','1','1','0','1','1'});
    vec.push_back({'1','1','1','0','1','1'});
    maximalRectangle(vec);
    return 0;
}