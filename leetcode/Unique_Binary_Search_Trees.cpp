/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Unique_Binary_Search_Trees.cpp
 * @author yaokun(com@baidu.com)
 * @date 2014/11/16 23:16:14
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

int numTrees(int n){
    int result[n+1];
    memset(result, 0, sizeof(int)*(n+1)); 
    //初始化
    result[0] = result[1] = 1;
    for(int j=2; j<=n; j++){
        //边界
        int bound = j/2;
        int i = 0;
        for(; i<bound; i++){
            result[j] += 2 * (result[i] * result[j-i-1]);
        }
        if (j%2 != 0){
            //如果是奇数
            result[j] += result[i] * result[j-i-1];
        }
    }
    return result[n];
}

int main(){
    cout << numTrees(5) << endl;
    return 0;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
