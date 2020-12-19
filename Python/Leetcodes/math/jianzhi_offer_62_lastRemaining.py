#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/19 3:46 下午
@Author  : luocai
@file    : jianzhi_offer_62_lastRemaining.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
剑指 offer62 题圆圈中最后的数字
"""
import sys

# Python 默认的递归深度不够，需要手动设置
sys.setrecursionlimit(100000)


class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 递归
        def f(n, m):
            if n == 0:
                return 0
            x = f(n - 1, m)
            return (m + x) % n

        return f(n, m)

    def lastRemaining2(self, n: int, m: int) -> int:
        # 迭代
        f = 0
        for i in range(2, n + 1):
            f = (m + f) % i
        return f
