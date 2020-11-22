#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/22 11:07 下午
@Author  : luocai
@file    : 509_fibonacci_number.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/fibonacci-number/
509题--斐波那契数
"""


class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        a, b = 0, 1
        for i in range(2, N+1):
            a, b = b, a + b
        return b


if __name__ == '__main__':
    n = 4
    print(f"n={n}")
    solution = Solution()
    print("result: ", solution.fib(n))
