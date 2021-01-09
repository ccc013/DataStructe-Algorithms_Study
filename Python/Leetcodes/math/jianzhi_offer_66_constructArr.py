#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/9 7:17 下午
@Author  : luocai
@file    : jianzhi_offer_66_constructArr.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
剑指 offer66 题--构建乘积数组
"""
from typing import List


class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        n = len(a)
        b, tmp = [1] * n, 1
        # 计算下三角
        for i in range(1, n):
            b[i] = b[i - 1] * a[i - 1]
        # 计算上三角和最终结果
        for i in range(n - 2, -1, -1):
            tmp *= a[i + 1]
            b[i] *= tmp
        return b
