#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/10 11:41 上午
@Author  : luocai
@file    : jianzhi_offer_19_isMatch.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 19. 正则表达式匹配
https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s) + 1, len(p) + 1
        dp = [[False] * n for _ in range(m)]
        dp[0][0] = True
        # 初始化首行
        for j in range(2, n, 2):
            dp[0][j] = dp[0][j - 2] and p[j - 1] == '*'

        # 状态转移
        for i in range(1, m):
            for j in range(1, n):
                if p[j - 1] == '*':
                    if dp[i][j - 2]:
                        dp[i][j] = True
                    elif dp[i][j - 1]:
                        dp[i][j] = True
                    elif dp[i - 1][j] and s[i - 1] == p[j - 2]:
                        dp[i][j] = True
                    elif dp[i - 1][j] and p[j - 2] == '.':
                        dp[i][j] = True
                else:
                    if dp[i - 1][j - 1] and s[i - 1] == p[j - 1]:
                        dp[i][j] = True
                    elif dp[i - 1][j - 1] and p[j - 1] == '.':
                        dp[i][j] = True

        return dp[-1][-1]
