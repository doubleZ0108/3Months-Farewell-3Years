//
//  pointer.c
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/07 .
//  Copyright © 2020 double Z. All rights reserved.
//
#include "stdio.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void testSwap(){
    int a=3, b=4;
    swap(&a, &b);
    printf("%d %d", a, b);
}

int main() {
    int a = 100;
    int *pa = &a;
    int **ppa = &pa;

    printf("%d", *ppa);


    return 0;
}