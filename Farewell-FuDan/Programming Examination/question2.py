# -*- coding: utf-8 -*-

'''
@program: question2.py

@author: 2021******* Zhe ZHANG

@create: 2020/09/21 
'''

import re
import numpy as np

def outputMatrix(matrix, peopleNum):
    for i in range(peopleNum):
        for j in range(peopleNum):
            print(matrix[i][j], end=" ")
        print()

def judgeConflict(M, peopleNum):
    for i in range(peopleNum):
        small_than_me = np.where(np.array(M[i]) == 1)[0]
        large_than_me = np.where(np.array(M[i]) == -1)[0]

        for large in large_than_me:
            for small in small_than_me:
                if M[large][small] == 0:
                    M[large][small] = 1
                elif M[large][small] != 1:
                    print("信息包含冲突")
                    return False

        for small in small_than_me:
            for large in large_than_me:
                if M[small][large] == 0:
                    M[small][large] = -1
                elif M[small][large] != -1:
                    print("信息包含冲突")
                    return False
    return M

def judgeComplete(M, peopleNum):
    for i in range(peopleNum):
        for j in range(peopleNum):
            if i!=j and M[i][j]==0:
                print("信息不完全")
                return False
    return True

def main():
    peopleNum, recordNum = map(int, input().split())

    '''
    [测试用例]
    
    peopleNum, recordNum = 3, 3
    records = [
        "0>1",
        "1<2",
        "0>2"
    ]

    peopleNum, recordNum = 4, 4
    records = [
        "1=2",
        "1>3",
        "2>0",
        "0>1"
    ]

    peopleNum, recordNum = 3, 2
    records = [
        "1>0",
        "1>2"
    ]
    '''

    M = [[0 for _ in range(peopleNum)] for _ in range(peopleNum)]
    for i in range(recordNum):
        record = input()
        # record = records[i]   # for test
        leftPeople = re.findall("\d+", record)[0]
        op = record[len(leftPeople)]
        rightPeople = re.findall("\d+", record)[1]
        left, right = int(leftPeople), int(rightPeople)

        if op=="<":
            M[left][right] = -1
            M[right][left] = 1
        elif op==">":
            M[left][right] = 1
            M[right][left] = -1
        else:
            M[left][right] = M[right][left] = 2

    outputMatrix(M, peopleNum)

    M = judgeConflict(M, peopleNum)
    if M is not False and judgeComplete(M, peopleNum):
            print("能确定")

if __name__ == '__main__':
    main()

