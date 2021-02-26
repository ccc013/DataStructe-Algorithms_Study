#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/26 7:58 上午
@Author  : luocai
@file    : 461_hammingDistance.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

461. 汉明距离
https://leetcode-cn.com/problems/hamming-distance/
"""


class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        res = x ^ y
        num = 0
        while res != 0:
            num += res & 1
            res >>= 1
        return num

    def hammingDistance2(self, x: int, y: int) -> int:
        res = x ^ y
        num = 0
        while res != 0:
            res = res & (res - 1)
            num += 1
        return num


if __name__ == '__main__':
    x = 1
    y = 4
    res = x ^ y
    solution = Solution()
    print('result:', solution.hammingDistance(x, y))
