#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/17 3:34 下午
@Author  : luocai
@file    : jianzhi_offer_46_translateNum.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
剑指 offer 46 题 把数字翻译成字符串
"""


class Solution:
    def translateNum(self, num: int) -> int:
        # 字符串遍历
        s = str(num)
        a = b = 1
        for i in range(2, len(s) + 1):
            tmp = s[i - 2:i]
            a, b = a + b if "10" <= tmp <= "25" else a, a
        return a

    def translateNum2(self, num: int) -> int:
        # 数字求余
        a = b = 1
        # 获取最后一位数字
        y = num % 10
        while num != 0:
            num //= 10
            x = num % 10
            tmp = 10 * x + y
            a, b = a + b if 10 <= tmp <= 25 else a, a
            y = x
        return a


if __name__ == '__main__':
    num = 12258
    solution = Solution()
    print("result: ", solution.translateNum(num))
    print("result: ", solution.translateNum2(num))
