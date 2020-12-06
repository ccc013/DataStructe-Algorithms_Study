#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/5 11:27 上午
@Author  : luocai
@file    : jianzhi_offer_58_reverseLeftWords.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
剑指 offer58 题--左旋转字符串
"""


class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        # 利用字符串的切片操作
        return s[n:] + s[:n]

    def reverseLeftWords2(self, s: str, n: int) -> str:
        # 字符串拼接
        res = ""
        length = len(s)
        for i in range(n, length):
            res += s[i]
        for i in range(n):
            res += s[i]
        return res

    def reverseLeftWords3(self, s: str, n: int) -> str:
        # 利用求余，简化代码
        res = ""
        length = len(s)
        for i in range(n, n+length):
            res += s[i % length]
        return res


if __name__ == '__main__':
    s = "lrloseumgh"
    k = 6
    print(f"origin string: {s}, k={k}")
    solution = Solution()
    print("after reverse string: ", solution.reverseLeftWords3(s, k))
