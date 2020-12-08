#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/8 7:32 上午
@Author  : luocai
@file    : jianzhi_offer_15_hammingWeight.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
剑指 offer15 题--二进制中 1 的个数
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return

    def hammingWeight2(self, n: int) -> int:
        count = 0
        while n:
            count += 1
            n &= n - 1
        return count


