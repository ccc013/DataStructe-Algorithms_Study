#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/30 1:35 下午
@Author  : luocai
@file    : jianzhi_offer_44_findNthDigit.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
剑指 Offer 44. 数字序列中某一位的数字
"""


class Solution:
    def findNthDigit(self, n: int) -> int:
        digit, start, count = 1, 1, 9
        # 1. 确定所求数位的所在数字的位数
        while n > count:
            n -= count
            start *= 10  # 1, 10, 100...
            digit += 1  # 1,2,3,..
            count = 9 * start * digit  # 9,180,2700...
        # 2. 确定所求数位所在的数字
        num = start + (n - 1) // digit
        # 3. 确定所求数位在 num 的哪一位
        return int(str(num)[(n - 1) % digit])


if __name__ == '__main__':
    n = 15
    solution = Solution()
    print("res=", solution.findNthDigit(n))
