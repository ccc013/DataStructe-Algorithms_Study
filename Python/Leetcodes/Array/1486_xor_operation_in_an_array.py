#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/22 10:13 下午
@Author  : luocai
@file    : 1486_xor_operation_in_an_array.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/xor-operation-in-an-array/
1486.数组异或操作
"""


class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        res = start
        for i in range(1, n):
            res ^= start + 2 * i
        return res


if __name__ == '__main__':
    n = 10
    start = 5
    print(f"n={n}, start={start}")
    solution = Solution()
    print("result: ", solution.xorOperation(n, start))
