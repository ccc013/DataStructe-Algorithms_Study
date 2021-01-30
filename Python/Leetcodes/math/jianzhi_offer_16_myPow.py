#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/30 2:38 下午
@Author  : luocai
@file    : jianzhi_offer_16_myPow.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 16. 数值的整数次方
https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
"""


class Solution:
    def myPow(self, x: float, n: int) -> float:
        # 暴力解决
        if n == 0:
            return 1.0

        abs_n = n * -1 if n < 0 else n
        res = x
        for i in range(1, abs_n):
            res *= x
        return res if n > 0 else 1 / res

    def myPow2(self, x: float, n: int) -> float:
        # 二分法角度来实现快速幂
        if x == 0:
            return 0
        res = 1
        if n < 0:
            x = 1 / x
            n = -n
        while n:
            # n 是奇数
            if n & 1:
                res *= x
            x *= x
            n >>= 1

        return res


if __name__ == '__main__':
    solution = Solution()
    print("res=", solution.myPow2(2.0, 10))
    print("res=", solution.myPow2(2.1, 3))
    print("res=", solution.myPow2(2.0, -2))
