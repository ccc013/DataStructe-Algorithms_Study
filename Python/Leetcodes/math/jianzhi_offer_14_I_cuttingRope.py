#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/10 11:50 下午
@Author  : luocai
@file    : jianzhi_offer_14_I_cuttingRope.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
剑指 offer14 题--剪绳子
"""
import math


class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1
        a, b = n // 3, n % 3
        if b == 0:
            return int(math.pow(3, a))
        if b == 1:
            return int(math.pow(3, a - 1) * 4)

        return int(math.pow(3, a) * 2)
