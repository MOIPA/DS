//
// Created by TZQ on 2021/7/23.
//
#include <stdio.h>

// 提前声明有这个函数
// 冒泡排序
void bubbleSort(int *data);

// 选择排序 TODO 以后做 一共8个排序方法
void selectSort(int data[]);

int main() {
    // 1. 准备测试数据
    int a[10] = {5, 11, 3, 24, 16, 8, 13, 7, 23, 11};

    // 冒泡
    bubbleSort(a);
    // 选择
    selectSort(a);

    printf("排序后：\n");
    for (int i = 0; i <= 9; i++) {
        printf("%d \t", a[i]);
    }

    return 0;
}

/**
 * 后续还有其他排序方法
 *  冒泡排序的思路：将一个数和它后面的数比较，如果大换到后面，如果换了再将这个数继续比对直到最后结束 遍历n次，所以冒泡第一次总是能找到一个最大哦或者
 *  最小的数，将所有数字都这么操作，就是N*N次 所以复杂度为 O(N^2)
*/
void bubbleSort(int *data) {
    // 不同于java 返回数组只能返回数组指针
    int i, j, k;
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9 - i; j++) {
            if (data[j] > data[j + 1]) {
                k = data[j + 1];
                data[j + 1] = data[j];
                data[j] = k;
            }
        }
    }
}

/**
 * 后续还有其他排序方法
 *
*/