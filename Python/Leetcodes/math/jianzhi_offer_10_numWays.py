#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/10 7:37 上午
@Author  : luocai
@file    : jianzhi_offer_10_numWays.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
剑指 offer10--青蛙跳台阶问题
"""


class Solution:
    def numWays(self, n: int) -> int:
        if n <= 1:
            return 1
        a = [1, 1]
        for i in range(2, n + 1):
            a.append(a[-1] + a[-2])
        return a[n] % 1000000007

    def numWays2(self, n: int) -> int:
        if n <= 1:
            return 1
        a = [1, 1]
        for i in range(2, n + 1):
            a.append(a[-1] + a[-2])
        return a[n] % 1000000007


if __name__ == '__main__':
    n = 7
    solution = Solution()
    print("result: ", solution.numWays2(n))
