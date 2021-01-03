#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/3 10:08 下午
@Author  : luocai
@file    : jianzhi_offer_49_nthUglyNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/chou-shu-lcof/
剑指 offer49题 丑数
"""


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp, a, b, c = [1] * n, 0, 0, 0
        for i in range(1, n):
            n2, n3, n5 = dp[a] * 2, dp[b] * 3, dp[c] * 5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2: a += 1
            if dp[i] == n3: b += 1
            if dp[i] == n5: c += 1

        return dp[-1]


if __name__ == '__main__':
    n = 10
    solution = Solution()
    print("result: ", solution.nthUglyNumber(n))
