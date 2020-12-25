#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/25 7:42 上午
@Author  : luocai
@file    : jianzhi_offer_64_sumNums.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/qiu-12n-lcof/
剑指 Offer 64. 求1+2+…+n
"""


class Solution:
    def sumNums(self, n: int) -> int:
        return n and (n + self.sumNums(n-1))


if __name__ == '__main__':
    n = 9
    solution = Solution()
    print("result: ", solution.sumNums(n))
