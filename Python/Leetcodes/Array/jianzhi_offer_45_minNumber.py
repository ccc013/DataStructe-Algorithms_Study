#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/10 2:05 下午
@Author  : luocai
@file    : jianzhi_offer_45_minNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
剑指 offer45 题--把数组排成最小的数
"""
from typing import List
import functools


class Solution:
    def minNumber(self, nums: List[int]) -> str:
        # 快速排序
        def fast_sort(l, r):
            if l >= r:
                return
            i, j = l, r
            while i < j:
                # 循环找到不符合条件的数值
                while strs[j] + strs[l] >= strs[l] + strs[j] and i < j:
                    j -= 1
                while strs[i] + strs[l] <= strs[l] + strs[i] and i < j:
                    i += 1
                strs[i], strs[j] = strs[j], strs[i]

            strs[i], strs[l] = strs[l], strs[i]
            fast_sort(l, i - 1)
            fast_sort(i + 1, r)

        strs = [str(num) for num in nums]
        fast_sort(0, len(nums) - 1)
        return ''.join(strs)

    def minNumber2(self, nums: List[int]) -> str:
        # 快速排序
        def sort_rule(x, y):
            a, b = x + y, y + x
            if a > b:
                return 1
            elif b > a:
                return -1
            else:
                return 0

        strs = [str(num) for num in nums]
        strs.sort(key=functools.cmp_to_key(sort_rule))
        return ''.join(strs)
