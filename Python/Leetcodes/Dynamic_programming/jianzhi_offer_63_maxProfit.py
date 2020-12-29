#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/30 7:34 上午
@Author  : luocai
@file    : jianzhi_offer_63_maxProfit.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
剑指 offer63 题 股票的最大利润
"""
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) < 1:
            return 0
        profit, min_v = 0, prices[0]
        n = len(prices)
        for i in range(1, n):
            min_v = min(min_v, prices[i])
            profit = max(profit, prices[i] - min_v)
        return profit


if __name__ == '__main__':
    prices = [7, 1, 5, 3, 6, 4]
    solution = Solution()
    print("result: ", solution.maxProfit(prices))
