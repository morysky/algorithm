/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file quick_sort.cpp
 * @author yaokun(com@baidu.com)
 * @date 2014/11/12 10:11:19
 * @brief 
 *  
 **/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
 * 随机函数
 * @brief type: 0全闭，1左开右闭，2左闭右开
 */
int myrand(int a, int b, int type){
    srand((unsigned)time(NULL));
    //mod求余的数
    int mod     = b-a;
    int offset  = a;
    if(0 == type){
        mod++;
    }
    else if(2 == type){
        offset++;
    }
    return (rand()%mod+offset);
}

//分割核心算法
int partition(int* arr, int start, int end){
    //这个pivot_key应该随机
    int pivot_key   = myrand(start, end, 0);
    int pivot       = arr[pivot_key];

    //交换到首位置
    swap(arr[start], arr[pivot_key]);
    int i=start;
    int j=start+1;
    while (j<= end){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    //把pivot放到相应的位置上
    swap(arr[start], arr[i]);
    return i;
}

//打印数组
void printArr(int *arr, int start, int end){
    for(int i=start; i<=end; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void quick_sort(int* arr, int start, int end){
    if (start>=end){
        return ;
    }
    int partition_point = partition(arr, start, end);
    quick_sort(arr, start, partition_point-1);
    quick_sort(arr, partition_point+1, end);
    return ;
}


int main(int argc, char** argv){
    const int arrSize = 10;
    int arrTest[arrSize] = {2,8,5,1,10,5,9,9,3,5};
    //cout << "partition is " << partition(arrTest, 0, arrSize-1) <<endl;
    cout << "quick sort algorithm" << endl;
    quick_sort(arrTest, 0, arrSize-1);
    printArr(arrTest, 0, arrSize-1);
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
