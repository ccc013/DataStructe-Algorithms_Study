#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/31 3:51 下午
@Author  : luocai
@file    : jianzhi_offer_14_II_cuttingRope.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
剑指 offer14 题 II 剪绳子
"""


class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1
        a, b, p = n // 3, n % 3, 1000000007
        if b == 0:
            return 3 ** a % p
        if b == 1:
            return 3 ** (a - 1) * 4 % p

        return 3 ** a * 2 % p
