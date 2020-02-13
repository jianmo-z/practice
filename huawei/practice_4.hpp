/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_4.hpp
 * 时间: 2/13/2020-1:03 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// 判断是不是素数
int isPrime(int n) {
    for (int i = 2; i < n; i++) {
        while (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int getNum(char * array, int len, int * aim) {
    int size = 0;
    int num = 0;
    for (int i = 0; i < len; ++i) {
        if(array[i] == ',' ) {
            if(isPrime(num))
                aim[size++] = num;
            num = 0;
        } else {
            num = num * 10 + array[i] - '0';
        }
    }
    if(isPrime(num))
        aim[size++] = num;
    return size;
}

void sort(int * aim, int len) {
    for(int i = len - 1; i > 0; --i) {
        for(int j = 0; j < i; ++j) {
            if(aim[i] < aim[j]) {
                int tmp = aim[i];
                aim[i] = aim[j];
                aim[j] = tmp;
            }
        }
    }

}

void printArray(int * data, int len) {
    if(len == 0) {
        printf("empty\0");
        return;
    }

    int pre = data[0];
    printf("%d", data[0]);
    for (int i = 1; i < len; ++i) {
        if(pre != data[i])  {
            if(i != len) {
                printf(",");
            }
            printf("%d", data[i]);
            pre = data[i];
        }
    }
}

int test() {
    char array[1001] = "";
    int data[1000];
    scanf("%s", array);

    int size = getNum(array, strlen(array), data);
    sort(data, size);
    printArray(data, size);

    return 0;
}
