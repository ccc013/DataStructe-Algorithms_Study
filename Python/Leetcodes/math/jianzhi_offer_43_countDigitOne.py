#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/10 10:26 上午
@Author  : luocai
@file    : jianzhi_offer_43_countDigitOne.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 43. 1～n 整数中 1 出现的次数
https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
"""


class Solution:
    def countDigitOne(self, n: int) -> int:
        digit, res = 1, 0
        high, cur, low = n // 10, n % 10, 0
        while high != 0 or cur != 0:
            if cur == 0:
                res += high * digit
            elif cur == 1:
                res += high * digit + low + 1
            else:
                res += (high + 1) * digit
            low += cur * digit
            cur = high % 10
            high //= 10
            digit *= 10

        return res


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.countDigitOne(13))
