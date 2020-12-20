#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/21 7:20 上午
@Author  : luocai
@file    : jianzhi_offer_65_add.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
剑指 offer65 题--不用加减乘除做加法
"""


class Solution:
    def add(self, a: int, b: int) -> int:
        x = 0xffffffff
        a, b = a & x, b & x
        while b != 0:
            a, b = a ^ b, (a & b) << 1 & x
        return a if a <= 0x7fffffff else ~(a ^ x)

    def add2(self, a: int, b: int) -> int:
        # 递归
        x = 0xffffffff
        if b == 0:
            return a if a <= 0x7fffffff else ~(a ^ x)

        # 转换成非进位和 + 进位
        return self.add2(a ^ b, (a & b) << 1)


if __name__ == '__main__':
    a, b = 1, 1
    solution = Solution()
    print("result: ", solution.add(a, b))
