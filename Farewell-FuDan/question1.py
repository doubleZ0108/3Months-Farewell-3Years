# -*- coding: utf-8 -*-

'''
@program: question1.py

@description: 给定一颗二叉树，树的每个节点的值为一个正整数，删除一条边使得剩下的 两颗子树的节点和的乘积最大。

@author: 2021******* Zhe ZHANG

@create: 2020/09/21 
'''
import queue

def getLeftChild(index, tree):
    if 2*index+1 < len(tree) and tree[2*index+1] != "null":
        return int(tree[2*index+1])
    else:
        return "null"

def getRightChild(index, tree):
    if 2*index+2 < len(tree) and tree[2*index+2] != "null":
        return int(tree[2*index+2])
    else:
        return "null"

def getSubTree(index, tree):
    if(tree[index]=="null"):
        return [0]

    Q = queue.Queue()
    Q.put(index)
    subTree = [int(tree[index])]

    while not Q.empty():
        node = Q.get()
        leftChild, rightChild = getLeftChild(node, tree), getRightChild(node, tree)
        if leftChild != "null":
            Q.put(2*node+1)
            subTree.append(leftChild)

        if rightChild != "null":
            Q.put(2*node+2)
            subTree.append(rightChild)
    return subTree

def isNumber(s):
  try:
    float(s)
  except ValueError:
    try:
      complex(s)
    except ValueError:
      return False
  return True

def main():
    tree = input().split(",")
    '''
    [测试用例]
    tree = ['1','2','3','4','5','6']
    tree = ['1','null','2','null','null','3','4','null','null','null','null','null','null','5','6']
        # 注. 对于第二个测试用例由于定义树的数据类型之时没关注到给出的形式，按照完全二叉树的方式进行存储，因此无法与原输入匹配，望老师见谅
    '''

    totalSum = 0
    for i in range(len(tree)):
        if isNumber(tree[i]):
            totalSum = totalSum + int(tree[i])

    maxMulti = 0
    maxIndex = -1
    for i in range(1, len(tree)):
        subTreeSum = sum(getSubTree(i, tree))
        thisMulti = subTreeSum * (totalSum - subTreeSum)
        if thisMulti > maxMulti:
            maxIndex = i        # best cutting branch
            maxMulti = thisMulti

    print(maxMulti)

if __name__ == '__main__':
    main()
