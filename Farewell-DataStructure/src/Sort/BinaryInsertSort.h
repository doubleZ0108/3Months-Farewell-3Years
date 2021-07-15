//
//  BinaryInsertSort.h
//  src
//  
//  Created by double Z on 2020/09/03 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef SRC_BINARYINSERTSORT_H
#define SRC_BINARYINSERTSORT_H
#include <vector>

int BinaryInsertPosition(int key, vector<int> &arr, int size){
    int low = 0, high = size - 1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void BinaryInsertSort(vector<int> &arr, int size){
    int pos;
    for(int i=1; i<size; ++i){
        pos = BinaryInsertPosition(arr[i], arr, i);
        int save = arr[i];
        int j = i;
        while(j > pos){
            arr[j] = arr[j-1];
            --j;
        }
        arr[pos] = save;
    }
}

void testBinaryInsertSort(){
    vector<int> arr = {5, -1, 8, 99, 2, -123, 0, 0, 1};

    BinaryInsertSort(arr, 9);

    for(auto iter = arr.begin(); iter != arr.end(); ++iter){
        cout << *iter << " ";
    }
}

#endif //SRC_BINARYINSERTSORT_H
