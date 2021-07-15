//
//  BinarySearch.h
//  src
//  
//  Created by double Z on 2020/09/03 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef SRC_BINARYSEARCH_H
#define SRC_BINARYSEARCH_H

int BinarySearch(int key, int arr[], int size){
    int mid;
    int low = 0, high = size-1;
    while(low <= high){
        mid = (low + high) /2;
        if(arr[mid] < key){
            low = mid + 1;
        } else if(arr[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int BinarySearch_recursive(int key, int arr[], int start, int end){
    if(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] < key){
            return BinarySearch_recursive(key, arr, mid+1, end);
        } else if(arr[mid] > key){
            return BinarySearch_recursive(key, arr, start, mid-1);
        } else {
            return mid;
        }
    }
    return -1;
}

/**
 * 原序列必须有序
 */
void testBinarySearch(){
    int arr[9] = {1, 3, 5, 6, 8, 9, 14, 78, 99};
    int key = 99;

//    int result = BinarySearch(key, arr, 9);
    int result = BinarySearch_recursive(key, arr, 0, 9-1);
    if(result == -1){
        cout << "Sorry, key not in the array" << endl;
    } else {
        cout << "The position is " << result << endl;
    }
}

#endif //SRC_BINARYSEARCH_H
