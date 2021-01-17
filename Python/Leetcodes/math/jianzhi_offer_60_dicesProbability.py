#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/17 2:00 下午
@Author  : luocai
@file    : jianzhi_offer_60_dicesProbability.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
剑指 offer60 题 n 个筛子的点数
"""
from typing import List


class Solution:
    def dicesProbability(self, n: int) -> List[float]:
        # 总次数
        sum_all = 6 ** n
        # 初始化, 索引 0 不取
        dp = [0 for i in range(6 * n + 1)]

        # 第一枚筛子投掷的情况
        for i in range(1, 7):
            dp[i] = 1

        # 从第二枚筛子开始计算每个点数出现的次数
        for i in range(2, n + 1):
            # 从大到小遍历
            for j in range(6 * i, i - 1, -1):
                # 每次投掷要从0更新dp[j]大小，点数和出现的次数要重新计算
                dp[j] = 0
                for cur in range(1, 7):
                    # 意思为上一轮的最小点数为i-1
                    if j - cur < i - 1:
                        break
                    dp[j] += dp[j - cur]
        res = []
        # 计算概率
        for i in range(n, 6 * n + 1):
            res.append(dp[i] * 1.0 / sum_all)
        return res
