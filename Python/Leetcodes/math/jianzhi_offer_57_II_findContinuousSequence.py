#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/19 2:20 下午
@Author  : luocai
@file    : jianzhi_offer_57_II_findContinuousSequence.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
剑指 offer57 题 II 和为 s 的连续正序列
"""
from typing import List


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # 双指针法
        res = []
        l, r = 1, 2
        while l < r:
            # 求当前范围内的序列的和
            sum = (l + r) * (r - l + 1) / 2
            if sum == target:
                tmp = [i for i in range(l, r + 1)]
                res.append(tmp)
                l += 1
            elif sum < target:
                r += 1
            else:
                l += 1
        return res

    def findContinuousSequence2(self, target: int) -> List[List[int]]:
        # 暴力解法
        res = []
        sums = 0
        limit = int((target - 1) / 2)
        for i in range(1, limit + 1):
            j = i
            while 1:
                sums += j
                if sums == target:
                    tmp = [i for i in range(i, j + 1)]
                    res.append(tmp)
                    sums = 0
                    break
                elif sums > target:
                    sums = 0
                    break
                j += 1
        return res
