//
//  ShellSort.h
//  src
//  
//  Created by double Z on 2020/09/03 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef SRC_SHELLSORT_H
#define SRC_SHELLSORT_H
#include <vector>

void ShellSort(vector<int> &arr){
    for(int gap = arr.size()/2; gap > 0; gap = (gap==2? 1: int(gap/2.2))){  //希尔增量排序外循环
        for(int i=0;i<arr.size()/gap; ++i){     // 对这么多组依次进行排序

            /* 对某一组而言 */
            for(int j=gap+i; j<arr.size(); j+=gap){
                int k=j;
                int save = arr[k];
                while(k-gap>-1 && save < arr[k-gap]){
                    arr[k] = arr[k-gap];
                    k -= gap;
                }
                arr[k] = save;
            }

        }
    }
}

void testShellSort(){
    vector<int> arr = {5, -1, 8, 99, 2, -123, 0, 0, 1};

    ShellSort(arr);

    for(auto iter = arr.begin(); iter != arr.end(); ++iter){
        cout << *iter << " ";
    }
}

#endif //SRC_SHELLSORT_H
