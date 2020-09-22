# -*- coding: utf-8 -*-

'''
@program: problem3.py

@description: 一条由字母 a-z 组成的消息通过如下方式编码成了一串数字，即 a -> 1，b -> 2，....，z -> 26，那么给定一串数字，求可能的解码方式数量。

@author: 2021******* Zhe ZHANG

@create: 2020/09/21 
'''

def getDecodeNum(code):
    if code=="" or code[0] == '0':
        return 0

    dp = [0]*len(code)
    dp[0] = 1

    for i in range(1,len(code)):
        if code[i]=='0':
            if code[i-1] in ['1','2']:
                dp[i] = dp[i-2] + 1
            else:
                return 0
        elif code[i]>='1' and code[i]<='6':
            if code[i-1] in ['1','2']:
                dp[i] = dp[i-2]+2
            else:
                dp[i] = dp[i-1]+1
        else:
            dp[i] = dp[i-1]+1
    return dp[len(code)-1]

def main():
    code = input()
    print(getDecodeNum(code))

if __name__ == '__main__':
    main()