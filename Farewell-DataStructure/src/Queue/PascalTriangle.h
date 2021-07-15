//
//  PascalTriangle.h
//  src
//  
//  Created by double Z on 2020/09/03 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef SRC_PASCALTRIANGLE_H
#define SRC_PASCALTRIANGLE_H

#include <iostream>
#include <queue>
using namespace std;

void PascalTriangle_one_loop(int rank){
    queue<int> Q;
    Q.push(1);
    Q.push(1);
    Q.push(0);

    int leftup = 0, up = 0;
    while(!Q.empty()){
        up = Q.front();
        Q.pop();

        if(up != 0){
            cout << up << " ";
            Q.push(leftup + up);
        } else {
            Q.push(leftup + up);
            Q.push(0);
            if(--rank == 0){
                cout << endl;
                break;
            }
        }

        leftup = up;
    }
}

void PascalTriangle_two_loop(int rank){
    queue<int> Q;
    Q.push(1);
    Q.push(1);

    int leftup = 0, up = 0;

    for(int i=1; i<=rank; ++i){
        Q.push(0);
        for(int j=0; j<i+2;++j){    // 第一行有3个数, ...
            up = Q.front();
            Q.pop();
            Q.push(leftup + up);
            leftup = up;
            if(up != 0){
                cout << up << " ";
            }
        }
    }
    cout << endl;
}

/**
 * 反倒是两重循环的for速度更快
 */
void testPascalTriangle(){
    clock_t start, end;

    start = clock();
    for(int i=0;i<10000;++i){
        PascalTriangle_one_loop(30);
    }
    end = clock();
    cout << "one loop cost time: " << end - start << endl;


    start = clock();
    for(int i=0;i<10000;++i){
        PascalTriangle_two_loop(30);
    }
    end = clock();
    cout << "two loop cost time: " << end - start << endl;
}

#endif //SRC_PASCALTRIANGLE_H
