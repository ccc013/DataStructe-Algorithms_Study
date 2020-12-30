#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/30 7:51 上午
@Author  : luocai
@file    : jianzhi_offer_47_maxValue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
剑指 offer47 题 礼物的最大价值
"""
from typing import List


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # 初始化第一行
        for i in range(1, n):
            grid[0][i] += grid[0][i - 1]
        # 初始化第一列
        for j in range(1, m):
            grid[j][0] += grid[j - 1][0]

        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1])

        return grid[m - 1][n - 1]

    def maxValue2(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [0 for i in range(n + 1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[j] = max(dp[j], dp[j - 1]) + grid[i - 1][j - 1]
        return dp[n]
