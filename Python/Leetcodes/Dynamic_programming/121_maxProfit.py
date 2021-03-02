#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/3/2 10:16 下午
@Author  : luocai
@file    : 121_maxProfit.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

121.买卖股票的最佳时机
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
"""
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # dp[i] 表示第 i 天的最大利润
        dp = [0 for i in range(len(prices))]
        n = len(prices)
        min_val = prices[0]
        for i in range(1, n):
            min_val = min(min_val, prices[i])
            dp[i] = max(dp[i - 1], prices[i] - min_val)

        return dp[-1]


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.maxProfit([7, 1, 5, 3, 6, 4]))
    print("result: ", solution.maxProfit([7, 6, 4, 3, 1]))
